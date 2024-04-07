n, m = map(int, input().split())

def is_sim(w1, w2):
    return w2 in w1+w1

words = [input() for _ in range(n)]
found = False
for i in range(n):
    for j in range(i+1, n):
        if is_sim(words[i], words[j]):
            print(i+1, j+1)
            found = True
            break
    if found: break
if not found: print("BOOM!")