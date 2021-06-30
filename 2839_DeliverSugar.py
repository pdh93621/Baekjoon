N = int(input())

num = -1

for i in range(N // 5, -1, -1):
    temp = N - 5*i 
    if not temp % 3:
        num = i + temp // 3 
        break

print(num)