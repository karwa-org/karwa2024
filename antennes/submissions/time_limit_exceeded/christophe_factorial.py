import itertools


n = int(input())

b = [int(input()) for _ in range(n)]
c = [int(input()) for _ in range(n)]

highest = [-1 for _ in range(n)]
maxi = -1
for it in itertools.permutations(c):
    c1, c2 = 0, [-1 for _ in range(n)]
    for i in range(n):
        c2[i] = b[i] * it[i]
        c1 += c2[i]
    if c1 > maxi:
        highest = c2
        maxi = c1

for i in range(n):
    print(highest[i])
