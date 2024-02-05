permutation = list(map(int, input().split()))

def pairmutation(perms):
    prod = 1
    for k in range(len(perms)):
        for l in range(len(perms)):
            if k >= l:
                continue
            else:
                i, j = k+1, l+1
                prod *= (perms[l] - perms[k])/(j-i)
    return prod

print("Pair" if pairmutation(permutation)==1 else "Impair")