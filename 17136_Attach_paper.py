from sys import stdin

sizes = [0 for _ in range(6)]
paper = [list(map(int, stdin.readline().split())) for _ in range(10)]
jobs = []
result = 1000
T = 0

def Getmatch(n, x, y):
    if not n or n + x >= 10 or n + y >= 10: return
    for i in range(x, x + n):
        for j in range(y, y + n):
            if not paper[i][j]: return

def Attachcolor(n, match):
    x, y = match
    if sizes[n] >= 5 or x + n > 10 or y + n > 10: return False

    for i in range(x, x + n):
        for j in range(y, y + n):
            if not paper[i][j]: return False

    for i in range(x, x + n):
        for j in range(y, y + n):
            paper[i][j] = 0
    sizes[n] += 1
    return True

def Detachcolor(n, match):
    for i in range(match[0], match[0] + n):
        for j in range(match[1], match[1] + n):
            paper[i][j] = 1
    sizes[n] -= 1

def dfs(m, k, total):
    global result
    if k == result or total == 0: 
        result = min(result, k)
        return
    if m == T: return

    j = jobs[m]
    if not paper[j[0]][j[1]]: dfs(m + 1, k, total)
    for n in range(5, 0, -1):
        if Attachcolor(n, j):
            dfs(m + 1, k + 1, total - (n ** 2))
            Detachcolor(n, j)

for i in range(10):
    for j in range(10):
        if paper[i][j]: jobs.append((i, j))
for n in range(6):
    for j in jobs:
        Getmatch(n, j[0], j[1])
T = len(jobs)

dfs(0, 0, T)

print((result != 1000) * result - (result == 1000))