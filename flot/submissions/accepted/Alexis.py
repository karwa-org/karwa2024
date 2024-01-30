from collections import deque, defaultdict

class Edge:
    def __init__(self, u, v, c):
        self.u = u
        self.v = v
        self.c = c

INF = 10**18

def solve():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]

    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(Edge(u, v, 5))

    d = int(input())
    start = [int(i) - 1 for i in input().split()]

    a = int(input())
    end = [int(i) - 1 for i in input().split()]

    q = deque()
    dist = [INF] * n

    min_start = {}
    in_q = defaultdict(bool)

    for i in range(len(start)):
        dist[start[i]] = 0
        min_start[start[i]] = start[i]
        in_q[start[i]] = True
        q.append(start[i])

    while q:
        current = q.popleft()
        in_q[current] = False

        for e in adj[current]:
            if dist[e.v] == INF or dist[e.v] == dist[e.u] + e.c:
                dist[e.v] = dist[e.u] + e.c

                if not in_q[e.v]:
                    q.append(e.v)
                    in_q[e.v] = True

                if e.v not in min_start:
                    min_start[e.v] = min_start[e.u]
                else:
                    min_start[e.v] = min(min_start[e.v], min_start[e.u])

    for i in range(len(end)):
        if end[i] not in min_start:
            print(-1, end=" ")
        else:
            print(min_start[end[i]] + 1, end= " ")
    print()

solve()
