def solve():
    n, a = map(int, input().split())
    ans = []

    for _ in range(n):
        data = input().split()
        s, m, other = data[0], data[1], data[2:]
        m = int(m)

        prev = -1
        maxii = -1e9
        for _ in range(m):
            x = int(other[_]) 
            if prev == -1:
                prev = x
                continue
            maxii = max(prev - x, maxii)
            prev = x
        if maxii <= a:
            ans.append(s)

    print(len(ans))
    for x in ans:
        print(x)

if __name__ == "__main__":
    solve()
