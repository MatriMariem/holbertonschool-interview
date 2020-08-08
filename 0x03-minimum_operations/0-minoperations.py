#!/usr/bin/python3
"""
here is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste.
Given a number n,
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def factorization(n):
    """ returns the sum of prime factors of n or n if n is prime"""
    sum = 0
    for i in range(2, n + 1):
        while n % i == 0:
            n = n // i
            sum += i
    return sum


def minOperations(n):
    """
    returns the fewest number of needed operations or 0
    """
    if not isinstance(n, int) or n < 2:
        return 0
    return factorization(n)
