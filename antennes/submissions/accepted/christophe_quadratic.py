n = int(input())
b = [int(input()) for _ in range(n)]
c = [int(input()) for _ in range(n)]
def get_max(t):
    maxi, idx = -1, -1
    for i, n in enumerate(t):
        if n > maxi: maxi, idx = n, i
    return maxi, idx
scores = [None for _ in range(n)]
for _ in range(n):
    m1, i1 = get_max(b)
    m2, i2 = get_max(c)
    scores[i1] = m1 * m2
    b[i1], c[i2] = -1, -1

for i in range(n):
    print(scores[i])
