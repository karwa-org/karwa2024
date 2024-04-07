import sys
sys.setrecursionlimit(1000000)

n, t = map(int, input().split())
p, c, e = [], [], []
for _ in range(n):
    p_, c_, e_ = map(int, input().split())
    p.append(p_)
    c.append(c_)
    e.append(e_)

def dfs(time_left, depth, prev_weap, prev_time):
    if time_left < 0:
        return depth-1, prev_time
    if depth >= n:
        return n, time_left

    if prev_weap >= 0:
        d, a = dfs(time_left - (p[depth] if prev_weap == 1 else c[depth]), depth+1, 1-prev_weap, time_left)
    else:
        d0, a0 = dfs(time_left - p[depth], depth+1, 0, time_left)
        d1, a1 = dfs(time_left - c[depth], depth+1, 1, time_left)
        if d0 > d1:
            d, a = d0, a0
        elif d1 > d0:
            d, a = d1, a1
        else:
            d, a = d0, max(a0, a1)

    d0, a0 = d, a
    d1, a1 = dfs(time_left - e[depth], depth+1, -1, time_left)
    if d0 > d1:
        d, a = d0, a0
    elif d1 > d0:
        d, a = d1, a1
    else:
        d, a = d0, max(a0, a1)

    return d, a

d, a = dfs(t, 0, -1, t)
print(f"{d} {t-a}")
