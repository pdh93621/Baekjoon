from collections import deque
T = int(input())

dx = [1,1,-1,-1,2,2,-2,-2]
dy = [2,-2,2,-2,1,-1,1,-1]

def BFS(D, start, target):
    if start == target:
        return 0
    
    DxD = []
    for _ in range(D):
        DxD.append([0 for _ in range(D)])

    queue = deque([start])
    DxD[start[0]][start[1]] = 1 

    while queue:    
        x, y = queue.popleft()
        
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]          
            if (0 <= nx < D) and (0 <= ny < D) and (DxD[nx][ny] == 0):
                DxD[nx][ny] = DxD[x][y] + 1
                if [nx,ny] == target:
                    return DxD[nx][ny] - 1
                queue.append([nx,ny])

for _ in range(T):
    D = int(input())
    start = list(map(int, input().split()))
    target = list(map(int, input().split()))

    print(BFS(D, start, target))