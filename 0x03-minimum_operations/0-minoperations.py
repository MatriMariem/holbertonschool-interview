#!/usr/bin/python3
"""
here is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste.
Given a number n,
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def isprime(n):
    """ checks if a number is prime
    """
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def prime_numbers(n):
    """ finds all prime numbers that are in [2, n[ """
    primes = []
    for i in range(2, n):
        if isprime(i):
            primes.append(i)
    return primes


def factorization(n, primes):
    """ returns the factorization of n """
    factors = []
    i = 0
    while n > 1:
        while n % primes[i] == 0:
            n = n // primes[i]
            factors.append(primes[i])
        i += 1
    return factors


def minOperations(n):
    """
    returns the fewest number of needed operations or 0
    """
    if not isinstance(n, int) or n < 2:
        return 0
    if isprime(n):
        return n
    primes = prime_numbers(n)
    factors = factorization(n, primes)
    return (sum(factors))
