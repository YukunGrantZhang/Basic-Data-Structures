# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 14:37:20 2020

@author: Grant
"""

from random import randrange

unsorted_list = [35, 1, 8, 2, 6, 11, 15, 9, 7, 25, 66, 88]
order_statistic = 6
result = 0

def ChoosePivot(left, right):
    global unsorted_list
    
    n = len(unsorted_list[left:right])
    pivot_list1 = unsorted_list[left:right]
    pivot_list = pivot_list1[:]
    
    broken_pivot_list = [pivot_list[i:i+5] for i in range(0, len(unsorted_list[left:right]), 5)]
    
    for a in broken_pivot_list:
        a.sort()
    
    C = []
    
    for b in broken_pivot_list:
        C.append(b[len(b)//2])
    
    median = C[len(C)//2]
    
    return unsorted_list.index(median)

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
    
    pivot = ChoosePivot(left, right)
    
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