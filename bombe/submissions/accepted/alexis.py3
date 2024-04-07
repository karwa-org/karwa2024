import sys
from collections import defaultdict

MOD = (1 << 60)
A = 911382323

def safe_mod(a, m):
    return (a % m + m) % m

def solve():
    n, m = map(int, input().split())
    a = [list(input()) for _ in range(n)]

    pre = [0] * m
    pre[0] = 1
    for i in range(1, m):
        pre[i] = safe_mod((pre[i-1] * A), MOD)

    hs = [0] * n
    cnt = defaultdict(lambda: [0, 0])

    for i in range(n):
        h = 0
        for j in range(m):
            h += ord(a[i][j]) * pre[j]
            h = safe_mod(h, MOD)
        hs[i] = h
        cnt[hs[i]][0] = i+1

    for i in range(n):
        for j in range(m):
            hs[i] -= (ord(a[i][m-j-1]) * pre[m-1]) % MOD
            hs[i] %= MOD
            hs[i] *= A
            hs[i] %= MOD
            hs[i] += ord(a[i][m-j-1])
            hs[i] %= MOD

            if cnt[hs[i]][0] == 0:
                cnt[hs[i]][0] = i+1
            elif cnt[hs[i]][1] == 0 and cnt[hs[i]][0] != (i+1):
                cnt[hs[i]][1] = i+1
            elif cnt[hs[i]][0] > i+1:
                cnt[hs[i]][0] = i+1
            elif cnt[hs[i]][1] > i+1:
                cnt[hs[i]][1] = i+1

    mini = (sys.maxsize, sys.maxsize)

    for k, v in cnt.items():
        if v[0] == 0 or v[1] == 0:
            continue
        if v[0] < mini[0] or ((v[0] == mini[0]) and v[1] < mini[1]) :
            mini = v

    if mini[0] == sys.maxsize and mini[1] == sys.maxsize:
        print("BOOM!")
    else:
        print(mini[0], mini[1])

if __name__ == "__main__":
    solve()
