import collections
import sys
input = sys.stdin.readline
MOD = (1 << 40)
A = 911382323

def safeMod(a, m):
    return (a % m + m) % m

def solve():
    n, m = map(int, input().split())
    a = [list(input()) for _ in range(n)]

    pre = [0] * m
    pre[0] = 1
    for i in range(1, m):
        pre[i] = safeMod(pre[i-1] * A, MOD)

    hs = [0] * n
    cnt = {}
    cnt = collections.defaultdict(lambda : (0, 0), cnt)

    for i in range(n):
        hash_val = 0
        for j in range(m):
            hash_val += ord(a[i][j]) * pre[j]
            hash_val = safeMod(hash_val, MOD)
        hs[i] = hash_val
        cnt[hs[i]] = (i+1, 0)

    for i in range(n):
        for j in range(m):
            hs[i] -= safeMod(ord(a[i][m-j-1]) * pre[m-1], MOD)
            hs[i] = safeMod(hs[i], MOD)
            hs[i] *= A
            hs[i] = safeMod(hs[i], MOD)
            hs[i] += ord(a[i][m-j-1])
            hs[i] = safeMod(hs[i], MOD)

            if cnt[hs[i]][0] == 0:
                cnt[hs[i]] = (i+1, 0)
            elif cnt[hs[i]][1] == 0 and cnt[hs[i]][0] != (i+1):
                cnt[hs[i]] = (cnt[hs[i]][0], i+1)
            elif cnt[hs[i]][0] > i+1:
                cnt[hs[i]] = (i+1, cnt[hs[i]][1])
            elif cnt[hs[i]][1] > i+1:
                cnt[hs[i]] = (cnt[hs[i]][0], i+1)


    mini = (float('inf'), float('inf'))

    for k, v in cnt.items():
        if v[0] == 0 or v[1] == 0:
            continue
        if v < mini:
            mini = v

    if mini == (float('inf'), float('inf')):
        print("BOOM!")
    else:
        print(mini[0], mini[1])

if __name__ == "__main__":
    solve()