from collections import deque

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def BFS(cabbage, M, N):
    queue = deque([cabbage[0]])
    cabbage.remove(cabbage[0])
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0<=nx<M) and (0<=ny<N) and ([nx, ny] in cabbage):
                #print(nx,ny)
                cabbage.remove([nx, ny])
                queue.append([nx, ny])
    return 1

T = int(input())
for _ in range(T):
    M, N, K = list(map(int,input().split()))
    #print(M, N, K)
    
    worm = 0
    cabbage = []

    for _ in range(K):
        temp = list(map(int, input().split()))
        cabbage.append(temp)
        #print(temp)

    while cabbage:
        #print(cabbage)
        worm += BFS(cabbage, M, N)

    print(worm)