n = int(input())
names = [input() for _ in range(n)]
nb_see, nb_seen = [0 for _ in range(n)], [0 for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j: continue
        print(f'? {names[i]} {names[j]}')
        ans = input()
        if ans == 'OUI':
            nb_see[i] += 1
            nb_seen[j] += 1
for i in range(n):
    if nb_see[i] == n-1 and nb_seen[i] == 0:
        print(f'! {names[i]}')
