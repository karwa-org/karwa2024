import collections

MOD = (1 << 62)
A = 911382323

def safe_mod(a, m):
    return (a % m + m) % m

def solve():
    n, m = map(int, input().split())
    a = [list(input().strip()) for _ in range(n)]

    pre = [0 for i in range (m)]
    pre[0] = 1
    for i in range(1, m):
        pre[i] = (pre[i - 1] * A) % MOD

    hs = [0 for i in range(n)]
    cnt = collections.defaultdict(set)

    for i in range(n):
        hash_val = 0
        for j in range(m):
            hash_val += ord(a[i][j]) * pre[j]
            hash_val %= MOD

        hs[i] = hash_val
        cnt[hs[i]].add(i + 1)
    #print(hs)
    for i in range(n):
        for j in range(m):
            hs[i] -= (ord(a[i][m - j - 1]) * pre[m - 1]) % MOD
            hs[i] %= MOD
            hs[i] *= A
            hs[i] %= MOD
            hs[i] += ord(a[i][m - j - 1])
            hs[i] %= MOD

            #print(hs[i], i + 1)
            cnt[hs[i]].add(i + 1)


    mini = (float('inf'), float('inf'))

    for k, v in cnt.items():
        #print(k, v)
        if len(v) > 1:
            prop = tuple(sorted(list(v))[:2])
            mini = min(mini, prop)

    if mini == (float('inf'), float('inf')):
        print("BOOM!")
    else:
        print(mini[0], mini[1])

if __name__ == "__main__":
    solve()
