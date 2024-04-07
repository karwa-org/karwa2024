n, m = map(int, input().split())

def is_sim(w1, w2):
    signature_w1 = 0
    signature_w2 = 0
    for i in range(m):
        signature_w1 += ord(w1[i]) * i
        signature_w2 += ord(w2[i]) * i

    return signature_w1 == signature_w2


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