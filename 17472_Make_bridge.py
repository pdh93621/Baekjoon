import heapq
from collections import deque

N, M = map(int, input().split())

Map = [list(map(int, input().split())) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
bridge = []
result = 1000000
dfs_map = []

def find_island(n, x, y):
    q = deque([(x, y)])
    visited[x][y] = n

    while q:
        nx, ny = q.popleft()
        
        for i in range(4):
            nnx = nx + dx[i]
            nny = ny + dy[i]
            if 0 <= nnx < N and 0 <= nny < M and not visited[nnx][nny] and Map[nnx][nny]:
                q.append((nnx, nny))
                visited[nnx][nny] = n 

def make_hb():
    start = -1
    for n in range(N):
        for m in range(M):
            if visited[n][m]:
                if start >= 0 and m - start > 2:
                    bridge.append((m - start - 1, visited[n][start], visited[n][m]))
                start = m
        start = -1

def make_vb():
    start = -1
    for m in range(M):
        for n in range(N):
            if visited[n][m]:
                if start >= 0 and n - start > 2:
                    bridge.append((n - start - 1, visited[start][m], visited[n][m]))
                
                start = n
        start = -1

def prim(n):
    result = 0
    visit = [False for _ in range(7)]
    visit[1] = 1
    hq = dfs_map[1]
    heapq.heapify(hq)

    while hq:
        d, start, end = heapq.heappop(hq)

        if not visit[end]:
            visit[end] = True
            result += d
            for i in dfs_map[end]:
                heapq.heappush(hq, i)

    return (sum(visit) == n) * result - (sum(visit) != n)

n = 1
for x in range(N):
    for y in range(M):
        if Map[x][y] and not visited[x][y]: 
            find_island(n, x, y)
            n += 1

make_hb()
make_vb()

bridge = list(set(bridge))
dfs_map = [[] for _ in range(n)]
for b in bridge:
    l, x, y = b
    dfs_map[x].append((l, x, y))
    dfs_map[y].append((l, y, x))

print(prim(n - 1))