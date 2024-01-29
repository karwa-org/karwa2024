#!/usr/bin/python3

n, sus = int(input()), 0
names = [input() for _ in range(n)]
for i in range(1, n):
    print(f'? {names[sus]} {names[i]}')
    ans = input()
    if ans == 'NON': sus = i
print(f'! {names[sus]}')
