# -*- coding: utf-8 -*-
"""
Created on Sun Jun 28 14:29:08 2020

@author: Grant
"""

months = ["january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"]

hashing_table = [[] for i in range(31)]

def hashingfunction(letters):
    numbers = []
    for letter in letters:
        number = ord(letter) - 96
        numbers.append(number)
    
    total = sum(numbers)
    
    compression_total = total % 31
    
    return compression_total
    
def Insert(letters):
    index = hashingfunction(letters)
    
    hashing_table[index].append(letters)

def Delete(letters):
    index = hashingfunction(letters)
    
    hashing_table[index].remove(letters)

def lookup(letters):
    index = hashingfunction(letters)
    
    if letters in hashing_table[index]:
        return True

for month in months:
    Insert(month)

print(hashing_table)


