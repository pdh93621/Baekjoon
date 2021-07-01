N = int(input())

if N < 3:
    dp = [0]*3
else:
    dp = [0]*(N+1)

dp[1] = 1
dp[2] = 2
n = 3
while n <= N:
    dp[n] = (dp[n-1] + dp[n-2]) % 15746
    n += 1

print(dp[N])