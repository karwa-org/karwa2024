n = int(input())
dists = [int(input()) for _ in range(n)]
length = sum(dists) + 1
pos = [False for i in range((int(1e6))+1)]
cur = 0

for i in range(n):
    pos[cur+dists[i]] = True
    cur += dists[i]

best_force, best_count = -1, -1
for force in range(2, length):
    count = 0
    for it in range(force, length, force):
        if pos[it]:
            count += 1
    if count >= best_count:
        best_force, best_count = force, count
print(best_force, best_count)