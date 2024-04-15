n, a = map(int,input().split())
accepted = []
for _ in range(n):
    name, o = input().split(' ', 1)
    o = list(map(int, o.split()))
    m, ups = o[0], o[1:]
    acc = True
    for i in range(m-1):
        if - ups[i+1] + ups[i] >= a:
            acc = False
            break
    if acc: accepted.append(name)
print(len(accepted))
for n in accepted:
    print(n)