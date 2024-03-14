from collections import defaultdict
from copy import copy
n, m = list(map(int, input().split()))
input()
succ = defaultdict(list)
for _ in range(m):
    i, j = list(map(int, input().split()))
    succ[i].append(j)
dist = defaultdict(lambda: 1e18)
dist[0] = 0
queue = [(0,0)]
visited = {0}
while queue:
    (cur, d) = queue.pop()
    for i in succ[cur]:
        if i not in visited:
            visited.add(i)
            queue.append((i,d+1))
            dist[i] = d+1
            if i == 1:
                queue = []
                break
if dist[1] == 1e18:
    print("IMPOSSIBLE")
else:
    print(dist[1] - 1)
