# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 10:05:56 2020

@author: Grant
"""

from random import randrange

unsorted_list = [35, 1, 8, 2, 6, 11, 15, 9, 7]
order_statistic = 3
result = 0

def Swap(x, y):
    global unsorted_list
    temp = unsorted_list[x]
    unsorted_list[x] = unsorted_list[y]
    unsorted_list[y] = temp

def Partition(left, right):
    global unsorted_list
    
    p = unsorted_list[left]
    i = left + 1
    
    for j in range(left + 1, right):
        if unsorted_list[j] < p:
            Swap(i, j)
            i += 1
    
    Swap(left, i-1)
    
    return i-1

def Rselect(left, right, i):
    global unsorted_list
    global result
    
    if right - left == 1:
        result = unsorted_list[left]
        return
    
    pivot = randrange(left, right)
    
    Swap(left, pivot)
    
    position = Partition(left, right)
    
    if position + 1 == i:
        result = unsorted_list[position]
        return
    
    if position + 1 > i:
        Rselect(left, position, i)
    
    if position + 1 < i:
        Rselect(position + 1, right, i)
    
len_unsorted_list = len(unsorted_list)
Rselect(0, len(unsorted_list), order_statistic)
print(result)