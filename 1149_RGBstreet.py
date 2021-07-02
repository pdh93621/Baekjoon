N = int(input())

prices = []
for _ in range(N):
    prices.append(list(map(int, input().split())))

for n in range(1,N):
    for m in range(3):
        prices[n][m] += min([prices[n-1][diff_color] for diff_color in [(m+1)%3, (m+2)%3]])
        
print(min(prices[N-1]))