# -*- coding: utf-8 -*-
"""
Created on Mon Jun 29 13:56:37 2020

@author: Grant
"""

import random

ips = ["112.15.6.55", "212.156.61.32", "136.111.63.121", "112.15.6.23", "52.151.62.48", "182.11.68.79", "212.156.61.111", "136.111.63.38", "91.115.61.121", "136.111.78.121", "52.151.62.71", "152.15.62.48"]

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
    global a1
    global a2
    global a3
    global a4
    global buckets
    
    buckets = get_nearest_prime(255)
    
    hashing_table = [[] for i in range(buckets)]
    
    a1 = random.randrange(0, buckets)
    a2 = random.randrange(0, buckets)
    a3 = random.randrange(0, buckets)
    a4 = random.randrange(0, buckets)

def hashingfunction(ip):    
    components = ip.split('.')
    
    num_components = []
    for c in components:
        num_components.append(int(c))
    
    hash_value = (a1 * num_components[0] + a2 * num_components[1] + a3 * num_components[2] + a4 * num_components[3]) % buckets
    
    return hash_value

def Insert(ip):
    index = hashingfunction(ip)
    
    hashing_table[index].append(ip)

def Delete(ip):
    index = hashingfunction(ip)
    
    hashing_table[index].remove(ip)

def lookup(ip):
    index = hashingfunction(ip)
    
    if ip in hashing_table[index]:
        return True

hashingtableinitialization()

for ip in ips:
    Insert(ip)

print(hashing_table)

