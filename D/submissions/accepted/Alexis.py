#!/usr/bin/env python3
import sys
input = sys.stdin.readline
n, k = map(int, input().strip().split(" "))
data = []
for i in range(n):
    name, cost = input().strip().split()
    cost = int(cost)
    data.append((name, cost))

dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range (1, n+1):
    for j in range (0, k+1):
        dp[i][j] = dp[i-1][j]
        if (j - data[i-1][1]) > 0 and (i -1) > 0 and dp[i-1][j - data[i-1][1]] != 0:
            dp[i][j] = dp[i-1][j - data[i-1][1]] | (1 << i)
        elif (j - data[i-1][1]) == 0:
            dp[i][j] = 1 << i

ans = []

for i in range (1, n+1):
    if (dp[i][k] != 0):
        mask = dp[i][k]
        for j in range(1, 64+1):
            if ((mask >> j) & 1) == 1:
                ans.append(data[j-1][0])
        break

ans_size = len(ans)
if ans_size == 0:
    print(-1)
else:
    print(ans_size)
    for i in ans: 
        print(i)
exit(0)