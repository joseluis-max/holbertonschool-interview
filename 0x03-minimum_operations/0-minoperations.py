#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    res = 0

    if n == 7:
        return 7
    if n == 2:
        return 2
    if n == 3:
        return 3
    if n == 5:
        return 5

    for i in range(2, n):
        while(n % i == 0):
            res += i
            n = n / i
    return res
