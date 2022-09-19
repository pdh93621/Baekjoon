from collections import deque

N = int(input())
people = list(map(int, input().split())) 

area = [[x - 1 for x in list(map(int, input().split()))[1:]] for _ in range(N)]
total = 0
result = 1000000

def another(ls):
    nls = ''
    for i in range(1, N):
        if str(i) not in ls: nls += str(i)
    return nls

def bfs(n, ls):
    visited = [False for _ in range(N)]
    p1 = 0
    q1 = deque([n])
    visited[n] = True
    p1 += people[n]

    while q1:
        m = q1.popleft()
        
        for a in area[m]:
            if str(a) in ls and not visited[a]:
                q1.append(a)
                visited[a] = True
                p1 += people[a]
    
    for l in ls: 
        if not visited[int(l)]: return False
    
    return p1

def get_comb(k, j, a):
    if k == N: return
    global result
    p1 = bfs(0, a)
    if p1: 
        als = another(a)
        p2 = bfs(int(als[0]), als)
        if p2: 
            result = min(result, abs(p1 - p2))

    for i in range(j, N):
        get_comb(k + 1, i + 1, a + str(i))

get_comb(1, 1, '0')

print((result != 1000000) * result - (result == 1000000))