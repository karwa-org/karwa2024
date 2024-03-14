from collections import defaultdict
from copy import copy
n, m = list(map(int, input().split()))
adv = {i for i, b in enumerate(list(map(int, input().split()))) if b}
succ = defaultdict(list)
for _ in range(m):
    i, j = list(map(int, input().split()))
    succ[i].append(j)
dist = defaultdict(lambda: 1e18)
dist[1] = 0
changed = True
while changed:
    changed = False
    new_dist = copy(dist)
    for i in range(n):
        if i in adv:
            v = max(map(lambda j: dist[j], succ[i])) + 1
        else:
            v = min(map(lambda j: dist[j], succ[i])) + 1
        if v < dist[i]:
            new_dist[i] = v
            changed = True
    dist = new_dist
if dist[0] == 1e18:
    print("IMPOSSIBLE")
else:
    print(dist[0] - 1)
