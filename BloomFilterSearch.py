# -*- coding: utf-8 -*-
"""
Created on Wed Jul  1 09:39:39 2020

@author: Grant
"""

import random

ips = ["112.15.6.55", "212.156.61.32", "136.111.63.121", "112.15.6.23", "52.151.62.48", "182.11.68.79", "212.156.61.111", "136.111.63.38", "91.115.61.121", "136.111.78.121", "52.151.62.71", "152.15.62.48"]

def bitarrayinitialization():
    global bit_array
    global a1
    global a2
    global a3
    global a4
    global buckets
    
    buckets = 255
    
    bit_array = buckets*[0]
    
    a1 = random.randrange(0, buckets)
    a2 = random.randrange(0, buckets)
    a3 = random.randrange(0, buckets)
    a4 = random.randrange(0, buckets)

def hashingfunction(ip):    
    components = ip.split('.')
    
    num_components = []
    for c in components:
        num_components.append(int(c))
    
    bit_positions = []
    bit_positions.append((a1 * num_components[0]) % buckets)
    bit_positions.append((a2 * num_components[1]) % buckets)
    bit_positions.append((a3 * num_components[2]) % buckets)
    bit_positions.append((a4 * num_components[3]) % buckets)
    
    return bit_positions

def Insert(ip):
    indices = hashingfunction(ip)
    
    for index in indices:
        bit_array[index] = 1

def lookup(ip):
    indices = hashingfunction(ip)
    
    count = 0
    
    for index in indices:
        if bit_array[index] == 1:
            count += 1
    
    if count == 4:
        return True
    else:
        return False

bitarrayinitialization()

for ip in ips:
    Insert(ip)

for a in range(12):
    print(lookup(ips[a]))