N = int(input())

wines = [0]
for _ in range(N):
    wines.append(int(input()))

dp = [0]
dp.append(wines[1])
if N > 1:
    dp.append(wines[1] + wines[2])

for n in range(3,N+1):
    dp.append(max(wines[n-1] + dp[n-3] + wines[n], dp[n-2] + wines[n], dp[n-1])) 

print(dp)
print(dp[N])