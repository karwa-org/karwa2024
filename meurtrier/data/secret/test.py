n = int(input().strip())
peoples = []
for i in range(n):
	a = input()
	peoples.append(a)
a = input()
print(n)
murder = input()
k = int(input().strip())
adj = {}

for j in range(k):
	a, b = input().strip().split(" ")

	if b == murder:
		print(a, b)
		print("merdeeeeeeeeeeeeeeeeeee")
	if not a in adj:
		adj[a] = []
	adj[a].append(b)

for i in range(0,n):
	if(len(adj.get(peoples[i], [])) == 9999):
		print(peoples[i])

print(len(adj[murder]))
print(len(adj["person9198"]))