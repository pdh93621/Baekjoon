N, C = list(map(int, input().split()))

coordinate = []
for _ in range(N):
    coordinate.append(int(input()))

coordinate.sort()

def possible(mid):
    rest_router = C-1
    pivot = 0
    for i in range(len(coordinate)):
        if coordinate[i] - coordinate[pivot] >= mid:
            rest_router -= 1
            if rest_router == 0:
                return 1          
            pivot = i
    return 0

start = 1
end = coordinate[-1] - coordinate[0]
result = 0

while start <= end:
    mid = (start + end) // 2
    
    if possible(mid):
        start = mid + 1
        result = mid
    else:
        end = mid - 1

print(result)
    
