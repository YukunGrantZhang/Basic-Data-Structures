# -*- coding: utf-8 -*-
"""
Created on Fri Jul 10 14:13:46 2020

@author: Grant
"""

values = [1, 2, 3, 4]

probabilities = [0.02, 0.23, 0.74, 0.01]

n = len(values) + 1

A = []

for a in range(0, n):
    A.append([])

for a in range(0, n):
    for b in range(0, n):
        A[a].append(0)

R = []

for a in range(0, n):
    R.append([])

for a in range(0, n):
    for b in range(0, n):
        R[a].append(0)

def OBT():
    for s in range(0, n - 1):
        for i in range(1, n):
            if i + s >= n:
                continue
        
            minimum = []
            root = []
        
            sum_p = 0
            for x in range(i, i + s + 1):
                sum_p += probabilities[i - 1]
        
            for r in range(i, i + s + 1):
                if r == 1:
                    temp_min = A[r + 1][i + s]
                elif r == n - 1:
                    temp_min = A[i][r - 1]
                else:
                    temp_min = A[i][r - 1] + A[r + 1][i + s]
            
                minimum.append(temp_min)
                root.append(r)
        
            min_value = min(minimum)
            root_index = minimum.index(min_value)
        
            A[i][i + s] = min_value + sum_p
            R[i][i + s] = root[root_index]
    
    del R[0]

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()
            
def Construct_OBST(i, j):
    if i == j:
        p = None
    else:
        p = Node(values[R[i][j] - 1])
        p.left = Construct_OBST(i, R[i][j] - 1)
        p.right = Construct_OBST(R[i][j], j)
    
    return p
        
OBT()
root = Construct_OBST(0, 4)
root.PrintTree()