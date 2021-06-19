num_city = int(input())
dist = list(map(int, input().split()))
price = list(map(int, input().split()))

price = price[:-1]

start_price = price[0]
result = 0

for i in range(num_city-1):
    if start_price > price[i]:
        start_price = price[i]
    
    result += start_price * dist[i]

print(result)
