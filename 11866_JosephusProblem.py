from collections import deque

N, K = list(map(int, input().split()))

circle = deque([i + 1 for i in range(N)])

count = 1

print('<',end='')
while True:
    if len(circle) == 1:
        print(circle.popleft(), end = '')
        break
    temp = circle.popleft()
    
    if count == K:
        print(str(temp)+',',end=' ')
        count = 1
    else:
        circle.append(temp)
        count += 1

print('>')