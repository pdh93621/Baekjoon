from collections import deque

r = [-1, 1]

def rot_gear(g, rot):
    if rot == 1: return g[-1] + g[:-1]
    else: return g[1:] + g[0]

def rot_gears(gear, num, rot):
    move_list = [[num, rot]]
    q = deque([[num, rot]])
    visited = [False for _ in range(4)]
    visited[num] = True

    while q:
        tn, tr = q.popleft()
        
        for i in r:
            if 0 <= tn + i < 4 and not visited[tn + i] and gear[tn][2 * i] != gear[tn + i][-2 * i]:
                q.append([tn + i, tr * -1])
                move_list.append([tn + i, tr * -1])
                visited[tn + i] = True 

    for m in move_list: gear[m[0]] = rot_gear(gear[m[0]], m[1])

result = 0
gear = [input() for _ in range(4)]
n = int(input())

while n:
    n -= 1
    num, rot = list(map(int, input().split()))
    rot_gears(gear, num - 1, rot)
    #print(gear)

for i in range(4):
    if gear[i][0] == "1":
        result += 2 ** i

print(result)