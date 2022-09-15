from sys import stdin

N = int(stdin.readline())

dp = [0 for _ in range(N + 2)]

for i in range(1, N + 1):
    t, w = list(map(int, stdin.readline().split()))
    T = i + t
    dp[i] = max(dp[i], dp[i - 1])
    if T <= N + 1: dp[T] = max(dp[T], dp[i] + w)

print(max(dp[-2:]))