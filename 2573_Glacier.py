from collections import deque
import copy

N, M = list(map(int,input().split()))

dx = [1,-1,0,0]
dy = [0,0,1,-1]

sea = []
for _ in range(N):
    sea.append(list(map(int, input().split())))

iced = []
for n in range(N):
    for m in range(M):
        if sea[n][m]:
            iced.append([n,m])

visited = [[0]*M for _ in range(N)]

def BFS(n, m):
    global sea
    global iced
    global visited

    q = deque([[n,m]])

    temp_sea = copy.deepcopy(sea)

    visited[n][m] = 1

    while q:
 
        x, y = q.popleft()
        water = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0<=nx<N) and (0<=ny<M):
                if (not visited[nx][ny]) and sea[nx][ny]:
                    visited[nx][ny] = 1
                    q.append([nx,ny])
                
                if sea[nx][ny] == 0:
                    water += 1
        if temp_sea[x][y] > water:
            temp_sea[x][y] -= water
        else:
            temp_sea[x][y] = 0
            iced.remove([x,y])
    
    sea = copy.deepcopy(temp_sea)
    

def merge_ice():
    global visited

    year = 0

    while iced:
        print(iced)
        glacier = 0
        for n in range(N):
            for m in range(M):
                if (not visited[n][m]) and sea[n][m]:
                    BFS(n,m)                    
                    glacier += 1
                    if glacier > 1:
                        return year
        year += 1
        visited = [[0]*M for _ in range(N)]
    
    return 0

print(merge_ice())