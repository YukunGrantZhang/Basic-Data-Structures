# -*- coding: utf-8 -*-
"""
Created on Sun Jun 14 10:56:57 2020

@author: Grant
"""
from random import randrange

unsorted_list = [3, 1, 8, 2, 6, 4, 5, 9, 7]
splitter = 0

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

def QuickSort(left, right):
    global unsorted_list
    
    if right - left == 1:
        return 0
    
    pivot = randrange(left, right)
    
    Swap(left, pivot)
    
    position = Partition(left, right)
    
    if position - left > 0:
        QuickSort(left, position)
    
    if right - position - 1 > 0:
        QuickSort(position + 1, right)
    
len_unsorted_list = len(unsorted_list)
QuickSort(0, len(unsorted_list))
print(unsorted_list)


