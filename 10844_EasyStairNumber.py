N = int(input())

dp = []
dp.append([0]*10)
dp.append([0] + [1]*9)

for n in range(2,N+1):    
    dp.append([])
    for m in range(10):
        if m == 0:
            dp[n].append(dp[n-1][1])
        elif m == 9:
            dp[n].append(dp[n-1][8])
        else:
            dp[n].append((dp[n-1][m-1] + dp[n-1][m+1]) % 1000000000)

print(sum(dp[N]) % 1000000000)