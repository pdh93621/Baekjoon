from collections import deque
N, M, K = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(N)]

def rotate_array(r, c, s):
    if not s: return
    q = deque([])

    for c1 in range(c - s, c + s): q.append(A[r - s][c1])
    for r1 in range(r - s, r + s): q.append(A[r1][c + s])
    for c2 in range(c + s, c - s, -1): q.append(A[r + s][c2])
    for r2 in range(r + s, r - s, -1): q.append(A[r2][c - s])

    q.appendleft(q.pop())

    for c1 in range(c - s, c + s): A[r - s][c1] = q.popleft()
    for r1 in range(r - s, r + s): A[r1][c + s] = q.popleft()
    for c2 in range(c + s, c - s, -1): A[r + s][c2] = q.popleft()
    for r2 in range(r + s, r - s, -1): A[r2][c - s] = q.popleft()

    rotate_array(r, c, s - 1)

for _ in range(K):
    r, c, s = map(int, input().split())
    rotate_array(r - 1, c - 1, s)

print(min(map(sum, A)))