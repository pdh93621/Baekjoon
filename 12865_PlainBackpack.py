N, K = list(map(int,input().split()))

objects = [[0,0]]
dp = [[0]*(K+1)]*(N+1)

for _ in range(N):
    objects.append(list(map(int,input().split())))

for n in range(1,N+1):
    w = objects[n][0] 
    v = objects[n][1]
    for k in range(1,K+1):
      
        if k < w:
            dp[n][k] = dp[n-1][k]            
        else:
            dp[n][k] = max(dp[n-1][k], v + dp[n-1][k-w])
print(dp[N][K])