string1 = input()
string2 = input()

N = len(string1)
M = len(string2)

dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]

for n in range(1, N + 1):
    for m in range(1, M + 1):
        if string1[n-1] == string2[m-1]:
            dp[n][m] = dp[n-1][m-1] + 1
        else:
            dp[n][m] = max(dp[n-1][m], dp[n][m-1])
            
print(dp[-1][-1])