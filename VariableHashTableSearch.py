# -*- coding: utf-8 -*-
"""
Created on Sun Jun 28 15:34:33 2020

@author: Grant
"""

months = ["january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"]

def get_nearest_prime(old_number):
    largest_prime = 0
    for num in range(old_number + 1, 2 * old_number) :
        for i in range(2,num):
            if num % i == 0:
                break
        else:
            largest_prime = num
    return largest_prime

def hashingtableinitialization():
    global hashing_table 
    
    n = len(months)
    
    buckets = get_nearest_prime(n)
    
    hashing_table = [[] for i in range(buckets)]

def hashingfunction(letters):
    n = len(months)
    
    buckets = get_nearest_prime(n) 
    
    numbers = []
    for letter in letters:
        number = ord(letter) - 96
        numbers.append(number)
    
    total = sum(numbers)
    
    compression_total = total % buckets
    
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

hashingtableinitialization()

for month in months:
    Insert(month)

print(hashing_table)

