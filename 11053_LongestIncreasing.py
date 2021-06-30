N = int(input())
A = list(map(int, input().split()))

dp = [1]*N

for n in range(1,N):
    for i in range(n):
        if A[i] < A[n]:
            dp[n] = max(dp[n], dp[i] + 1)

print(dp)
print(max(dp))
