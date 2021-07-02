N = int(input())
triangle = []
for _ in range(N):
    triangle.append(list(map(int,input().split())))

for n in range(1,N):
    for m in range(n+1):
        if m == 0:
            left = 0
        else:
            left = triangle[n-1][m-1]
        if m == n:
            right = 0
        else:
            right = triangle[n-1][m]
        triangle[n][m] += max(left, right)

print(triangle)
print(max(triangle[N-1]))