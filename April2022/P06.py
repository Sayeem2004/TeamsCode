# Solved by Nicholas Tarsis & Mark Ma
from math import sqrt, gcd

n = int(input())
nums = [int(x) for x in input().split()]
factors = []
for i in range(1, int(sqrt(n))+1):
    if n % i == 0:
        if i * i == n:
            factors.append(i)
        else:
            factors.append(i)
            factors.append(n//i)
check = {}
for i in factors:
    check[i] = 0
for i in factors:
    k = 0
    for j in range(n//i):
        check[i] += nums[k]
        k += i
        k %= n
su = 0
for i in nums:
    su += i
for i in range(1, n+1):
    a = gcd(i, n)
    if a == 1:
        print(su)
    else:
        print(check[a])
