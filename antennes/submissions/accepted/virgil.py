#!/usr/bin/env python3
n = int(input().strip())
bat = []
for i in range(n):
    b = int(input().strip())
    bat.append([b, i])
antennas = []
for i in range(n):
    c =  int(input().strip())
    antennas.append(c)

bat.sort(key=lambda el: el[0], reverse=True)
antennas.sort(reverse=True)
for i in range(n):
    bat[i][0] *= antennas[i]
bat.sort(key=lambda el: el[1])

for i in range(n):
    print(bat[i][0])
