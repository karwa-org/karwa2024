n = int(input())
idx_to_nb = list(map(lambda x: int(x)-1, input().split()))
nb_to_idx = [-1 for _ in range(n)]
for i in range(n):
    nb_to_idx[idx_to_nb[i]] = i

even = True
for i in range(n):
    if idx_to_nb[i] > i:
        t = idx_to_nb[i]
        idx_to_nb[i], idx_to_nb[nb_to_idx[i]] = idx_to_nb[nb_to_idx[i]], t
        nb_to_idx[i], nb_to_idx[t] = nb_to_idx[t], nb_to_idx[i]
        even = not even

print('Pair' if even else 'Impair')