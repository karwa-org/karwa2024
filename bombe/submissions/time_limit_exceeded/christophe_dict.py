from collections import defaultdict
n, m = map(int, input().split())

d = defaultdict(lambda: 1e18)
m1, m2 = 1e18, 1e18
for i in range(1, n+1):
    c = input()
    for _ in range(m):
        if d[c] < 1e18:
            if d[c] != i and d[c] < m1:
                m1, m2 = d[c], i
        else:
            d[c] = i
        c_ = c[-1] + c[:-1]
        #if c_ == c: break
        c = c_
if m1 != 1e18:
    print(m1, m2)
else:
    print("BOOM!")
