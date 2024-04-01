
mod = 10**9+7
n = int(input())
hub_x, hub_y, hub_xx, hub_yy = 0,0,0,0
par_x, par_y, par_xx, par_yy = 0,0,0,0
for _ in range(n):
    x, y = list(map(int, input().split()))
    hub_x += x
    hub_y += y
    hub_xx += x*x
    hub_yy += y*y
m = int(input())
for _ in range(m):
    x, y = list(map(int, input().split()))
    par_x += x
    par_y += y
    par_xx += x*x
    par_yy += y*y

squared = n*par_xx + n*par_yy + m*hub_xx + m*hub_yy
minus = par_x*hub_x + par_y*hub_y

print((squared - 2*minus)%mod)