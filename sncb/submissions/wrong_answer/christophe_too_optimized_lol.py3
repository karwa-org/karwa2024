from collections import defaultdict
from copy import copy
n, m = list(map(int, input().split()))
adv = {i for i, b in enumerate(list(map(int, input().split()))) if b}
succ = defaultdict(list)
pred = defaultdict(list)
for _ in range(m):
    i, j = list(map(int, input().split()))
    succ[i].append(j)
    pred[j].append(i)
dist = defaultdict(lambda: 1e18)
dist[1] = 0
changed, finished = True, False
to_check = [1]
locked = {1}
while changed and not finished:
    new_to_check = []
    changed = False
    new_dist = copy(dist)
    while to_check:
        cur = to_check.pop()
        for i in pred[cur]:
            if i in locked: continue
            if i in adv:
                v = max(map(lambda j: dist[j], succ[i])) + 1
            else:
                v = min(map(lambda j: dist[j], succ[i])) + 1
            if not changed and v < dist[i]:
                new_dist[i] = v
                changed = True
                locked.add(i)
                new_to_check.append(i)
                if i == 0:
                    finished = True
    dist = new_dist
    to_check = new_to_check
if dist[0] == 1e18:
    print("IMPOSSIBLE")
else:
    print(dist[0] - 1)
