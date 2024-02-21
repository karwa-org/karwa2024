import sys
input = sys.stdin.readline

n = int(input())
s = 0
inside = [False for i in range((int(1e6))+1)]

for i in range(n):
    x = int(input())
    inside[s+x] = True
    s += x

best = 0
step = 0
for i in range(2, (s+1)):
    got = 0
    for j in range(i, (s+1), i):
        if inside[j]:
            got +=1
    if got > best:
        best = got
        step = i

print(step, best)
