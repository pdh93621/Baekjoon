N = int(input())
k = int(input())

start = 1
end = N*N
result = 0

while start <= end:
    mid = (start + end) // 2
    temp = 0
    for n in range(1,N+1):
        temp += min(mid//n, N)

    if temp >= k:
        result = mid
        end = mid - 1
    else:
        start = mid + 1    

print(result)