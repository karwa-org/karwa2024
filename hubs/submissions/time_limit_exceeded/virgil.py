#!/usr/bin/env python3

n = int(input())
hubs = []

for _ in range(n):
    hubs.append(tuple(map(int, input().split())))

m = int(input())
res = 0
for _ in range(m):
    x, y = tuple(map(int, input().split()))
    for i in range(n):
        res += (x - hubs[i][0])**2 + (y - hubs[i][1])**2
print(res%(10**9+7))
