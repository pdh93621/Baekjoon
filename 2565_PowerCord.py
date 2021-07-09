N = int(input())

wires = []
for _ in range(N):
    wires.append(list(map(int, input().split())))

wires.sort()

dp = [1]*N

for n in range(N):
    for i in range(n):
        if wires[i][1] < wires[n][1]:
            dp[n] = max(dp[n], dp[i] + 1)

print(N-max(dp))