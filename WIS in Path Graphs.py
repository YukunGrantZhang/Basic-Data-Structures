# -*- coding: utf-8 -*-
"""
Created on Thu Jul  9 14:13:19 2020

@author: Grant
"""

v = [1, 4, 5, 4]

n = len(v) + 1

A = [0, 1]

for i in range(2, n):
    case_1 = A[i - 1]
    case_2 = A[i - 2] + v[i - 1]
    max_value = max(case_1, case_2)

    A.append(max_value)

print(A)

S = []

m = n - 1

while m >= 1:
    if A[m - 1] >= A[m - 2] + v[m - 1]:
        m -= 1
    else:
        S.append(v[m - 1])
        m -= 2

print(S)        