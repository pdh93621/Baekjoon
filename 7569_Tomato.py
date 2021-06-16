from collections import deque

# 가로 M, 세로 N
M, N, H = list(map(int, input().split()))

box = []

for h in range(H):
    box.append([])
    for n in range(N):
        box[h].append(list(map(int, input().split())))

# 가능한 방향
dn = [1,-1,0,0,0,0]
dm = [0,0,1,-1,0,0]
dh = [0,0,0,0,1,-1]

def BFS(good):
    queue = deque(good)   
    day = 1
    while queue:
        temp = queue.popleft()
        for i in range(6):
            nh = temp[0] + dh[i]
            nn = temp[1] + dn[i]
            nm = temp[2] + dm[i]
            if (0 <= nh < H) and (0 <= nn < N) and (0 <= nm < M):
                if box[nh][nn][nm] == 0:
                    box[nh][nn][nm] = box[temp[0]][temp[1]][temp[2]] + 1
                    day = box[nh][nn][nm]
                    queue.append([nh,nn,nm])
    return day-1

good = []
for h in range(H):
    for n in range(N):
        for m in range(M):
            if box[h][n][m] == 1:
                good.append([h,n,m])

day = BFS(good)

for h in range(H):
    for n in range(N):
        if 0 in box[h][n]:
            day = -1
            break
print(day)