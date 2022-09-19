N, M = list(map(int, input().split()))

trees = list(map(int, input().split()))

start = 0
end = max(trees)
result = 0

while start <= end:
    mid = (start + end) // 2
    temp = 0
    for tree in trees:
        if tree > mid:
            temp += tree - mid
    
    if temp >= M:
        start = mid + 1
        result = mid
    else:
        end = mid - 1
    
print(result)