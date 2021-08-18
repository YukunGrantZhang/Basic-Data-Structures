# -*- coding: utf-8 -*-
"""
Created on Tue Jul  7 10:01:01 2020

@author: Grant
"""

characters = [["A", 3, None], ["B", 2, None], ["C", 6, None], ["D", 8, None], ["E", 2, None], ["F", 6, None]]

codes = ["000", "0010", "0011", "01", "10", "11"]

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def findcharacter(self, code):
        num_list = list(map(int, code))
        
        len_num = len(num_list)
        
        current_node = self
        for i in range (0, len_num):
            if num_list[i] == 0:
                current_node = current_node.left
            if num_list[i] == 1:
                current_node = current_node.right
        
        return current_node.data
        
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()

def merge(characters1, characters2):
    if characters1[2] == None and characters2[2] == None:
        left_node = Node(characters1[0])
        right_node = Node(characters2[0])
        
        centre_node = Node(None)
        centre_node.left = left_node
        centre_node.right = right_node
        
        return centre_node
    
    if characters1[2] != None and characters2[2] != None:
        left_node = characters1[2]
        right_node = characters2[2]
        
        centre_node = Node(None)
        centre_node.left = left_node
        centre_node.right = right_node
        
        return centre_node
    
    if characters1[2] == None and characters2[2] != None:
        left_node = Node(characters1[0])
        right_node = characters2[2]
        
        centre_node = Node(None)
        centre_node.left = left_node
        centre_node.right = right_node
        
        return centre_node
    
    if characters1[2] != None and characters2[2] == None:
        left_node = characters1[2]
        right_node = Node(characters2[0])
        
        centre_node = Node(None)
        centre_node.left = left_node
        centre_node.right = right_node
        
        return centre_node

def createHuffmanCodes(characters):
    if (len(characters) == 2):
        left_node = Node(characters[0][0])
        right_node = Node(characters[1][0])
        
        centre_node = Node(None)
        centre_node.left = left_node
        centre_node.right = right_node
        
        return centre_node
    
    while (len(characters) > 1):
        if len(characters) > 2:
            characters.sort(key = lambda x: x[1])
        
        a = characters[0][0]
        b = characters[1][0]
        a_weight = characters[0][1]
        b_weight = characters[1][1]
    
        new_characters = a + b
        new_weight = a_weight + b_weight
        new_root = merge(characters[0], characters[1])
        new_element = [new_characters, new_weight, new_root]
        
        del characters[0]
        del characters[0]
        characters.insert(0, new_element)
    
    return characters[0][2]

tree = createHuffmanCodes(characters)

for e in codes:
    character = tree.findcharacter(e)
    print(character)