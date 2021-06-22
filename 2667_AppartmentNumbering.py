import copy
from collections import deque

D = int(input())

apart = []
for n in range(D):
    string = input()
    temp = []
    for s in string:
        temp.append(int(s))
    apart.append(temp)

visited = apart.copy()

dn = [1,-1,0,0]
dm = [0,0,1,-1]

def BFS(start, D):
    size = 1
    queue = deque([start])
    visited[start[0]][start[1]] = 0

    while queue:
        n, m = queue.popleft()
        for i in range(len(dn)):
            nn = n + dn[i]
            nm = m + dm[i]
            if nn < D and nm < D and nn >= 0 and nm >= 0 and visited[nn][nm]:
                size += 1
                queue.append([nn, nm])
                visited[nn][nm] = False

    return size

size_apart = []

for n in range(D):
    for m in range(D):
        if visited[n][m]:
            size_apart.append(BFS([n,m], D))

size_apart.sort()
print(len(size_apart))
for size in size_apart:
    print(size)
    