n, t = map(int, input().split())
p, c, e = [], [], []
for _ in range(n):
    p_, c_, e_ = map(int, input().split())
    p.append(p_);c.append(c_);e.append(e_)
dp = [[int(-1e9) for _ in range(2)] for _ in range(n)]
dp[0][1], dp[0][0] = max(t - p[0], t - e[0]), max(t - c[0], t - e[0])
for i in range(1, n):
    dp[i][1] = max(max(dp[i-1][0] - p[i], dp[i-1][1] - e[i]), dp[i-1][0] - e[i])
    dp[i][0] = max(max(dp[i-1][1] - c[i], dp[i-1][0] - e[i]), dp[i-1][1] - e[i])
ans, maxi = 0, int(-1e9)
for i in range(n):
    if dp[i][0] >= 0:
        ans, maxi = i, dp[i][0]
    if dp[i][1] >= 0:
        ans, maxi = i, max(maxi, dp[i][1]) if ans == i else dp[i][1]
print(f"{ans+1} {t-maxi}")
