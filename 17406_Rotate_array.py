from collections import deque
N, M, K = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(N)]
R = [list(map(int, input().split())) for _ in range(K)]
result = 1000000
visited = [False for _ in range(K)]

def rotate_array(r, c, s, inverse = 1):
    if not s: return
    q = deque([])

    for c1 in range(c - s, c + s): q.append(A[r - s][c1])
    for r1 in range(r - s, r + s): q.append(A[r1][c + s])
    for c2 in range(c + s, c - s, -1): q.append(A[r + s][c2])
    for r2 in range(r + s, r - s, -1): q.append(A[r2][c - s])

    if inverse: q.appendleft(q.pop())
    else: q.append(q.popleft())

    for c1 in range(c - s, c + s): A[r - s][c1] = q.popleft()
    for r1 in range(r - s, r + s): A[r1][c + s] = q.popleft()
    for c2 in range(c + s, c - s, -1): A[r + s][c2] = q.popleft()
    for r2 in range(r + s, r - s, -1): A[r2][c - s] = q.popleft()

    rotate_array(r, c, s - 1, inverse)

def dfs(n = 0):
    if n == K:
        global result
        result = min(min(map(sum, A)), result)
    for k in range(K):
        if not visited[k]:
            visited[k] = True
            r, c, s = R[k]
            rotate_array(r - 1, c - 1, s)
            dfs(n + 1)
            visited[k] = False
            rotate_array(r - 1, c - 1, s, 0)

dfs()

print(result)