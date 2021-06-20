import copy

N, M = list(map(int, input().split()))
sea = []

for n in range(N):
    sea.append(list(map(int, input().split())))

# 방향
dn = [1,-1,0,0]
dm = [0,0,1,-1]

# 초기 빙산이 있는 위치 찾기
def find_ice(sea):
    visited = []
    for n in range(N):
        for m in range(M):
            if sea[n][m]:
                visited.append([n,m])
    return visited

# 하나의 빙산
def DFS(sea, start, visited):
    n, m = start
    visited.remove(start)
    for i in range(4):
        nn = n + dn[i]
        nm = m + dm[i]
        if [nn, nm] in visited:
            DFS(sea,[nn,nm], visited)

# 빙산의 수
iberg = 0
# 경과 시간
year = 0

# 빙산이 있는 곳 찾아서 저장
visited = find_ice(sea)

# 모든 빙산이 녹을때 까지 반복
while visited:

    # DFS에 들어갈 위치 저장소 생성
    visited2 = visited.copy()

    # 해당 년도 모든 빙산의 수 세기
    while visited2:
        DFS(sea, visited2[0],visited2)
        iberg += 1
    
    # 만약 빙산의 수가 1 초과 하면 반복문 탈출, 아니면 빙산 수 초기화
    if iberg > 1:
        break
    else:
        iberg = 0

    # 시간의 경과에 따라 빙산의 높이 -1하고 높이가 0이된 위치는 삭제 리스트에 추가
    list_remove = []
    for v in visited:
        sea[v[0]][v[1]] -= 1
        if sea[v[0]][v[1]] == 0:
            list_remove.append(v)

    # 삭제 리스트에 있는 위치는 빙산 위치에서 제거
    for r in list_remove:
        visited.remove(r)

    year += 1

if iberg > 1:
    print(year)
else:
    print(0)