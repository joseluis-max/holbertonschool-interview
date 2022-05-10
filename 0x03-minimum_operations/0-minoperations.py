#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    res = 0
    for i in range(2, n):
        while(n%i == 0):
            res += i
            n = n/i
    return res
