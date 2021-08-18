# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 10:23:26 2020

@author: Grant
"""

unsorted_list = [3, 1, 8, 2, 6, 4, 5, 9, 7]

def merge(first_half, second_half):
    output_length = len(first_half) + len(second_half)
    
    i_length = len(first_half)
    j_length = len(second_half)
    i = 0
    j = 0
    
    output_list = []
    
    for k in range(output_length):
        if i == i_length:
            output_list.append(second_half[j])
            j += 1
            continue
        
        if j == j_length:
            output_list.append(first_half[i])
            i += 1
            continue
        
        if first_half[i] < second_half[j]:
            output_list.append(first_half[i])
            i += 1
        else:
            output_list.append(second_half[j])
            j += 1
    
    return output_list

def merge_sort(input_list):
    input_list_length = len(input_list)
    middle_index = input_list_length//2
    
    first_half = input_list[:middle_index]
    second_half = input_list[middle_index:]    

    if len(input_list) >= 3:
        new_first_half = merge_sort(first_half)
        new_second_half = merge_sort(second_half)
        
        return merge(new_first_half, new_second_half)
    else:
        return merge(first_half, second_half)
            
result = merge_sort(unsorted_list)

print(result)
    