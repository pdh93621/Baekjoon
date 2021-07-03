N = int(input())

stairs = []
dp = [0]*N
for _ in range(N):
    stairs.append(int(input()))

dp[0] = stairs[0]
dp[1] = stairs[0] + stairs[1]
dp[2] = stairs[2] + max(stairs[0],stairs[1])

for i in range(3, N):
    dp[i] = stairs[i] + max(dp[i-3]+stairs[i-1], dp[i-2])

print(dp[-1])