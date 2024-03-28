#!/usr/bin/env python3

n = int(input())
sumA, sumB, sumA2, sumB2 = 0, 0, 0, 0
for _ in range(n):
    a, b   = map(int,input().split())
    sumA  += a
    sumA2 += a**2
    sumB  += b
    sumB2 += b**2
m = int(input())
sumX, sumY, sumX2, sumY2 = 0, 0, 0, 0
for _ in range(m):
    x, y = map(int,input().split())
    sumX  += x
    sumX2 += x**2
    sumY  += y
    sumY2 += y**2
M   = 1000000007
ans = (((n*(sumX2+sumY2))%M+(m*(sumA2+sumB2))%M)-2*((sumX*sumA)%M+(sumY*sumB)%M) + M)%M
print(ans)
