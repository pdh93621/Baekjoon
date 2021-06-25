from collections import deque

N, K = list(map(int,input().split()))
line = [0] * 100001

def move(x):
    return x-1, x+1, x*2

def seek(start, target):
    if start == target:
        return 0
    
    queue = deque([start])

    while True:        
        position = queue.popleft()
        time = line[position] + 1
        for new in move(position):
            if new == target:
                return time
            
            if (0 <= new <= 100000) and (not line[new]):  
                queue.append(new)
                line[new] = time 
    
    
print(seek(N,K))