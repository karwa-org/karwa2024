permutation = list(map(int, input().split()))

def pairmutation(perms):
    prod = 1
    for k in range(len(perms)):
        for l in range(len(perms)):
            if k >= l:
                continue
            else:
                i, j = k+1, l+1
                prod *= -1 if (perms[l] - perms[k])/(j-i) < 0 else 1
    return prod

print("Pair" if pairmutation(permutation) > 0 else "Impair")