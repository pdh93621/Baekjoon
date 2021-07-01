T = int(input())

numbers = []

for _ in range(T):
    numbers.append(int(input()))

dp = [0]*(max(numbers)+1)

def divide_sum(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4

    if dp[n] != 0:
        return dp[n]
    
    dp[n] = divide_sum(n-1) + divide_sum(n-2) + divide_sum(n-3)
    return dp[n]

for n in numbers:
    print(divide_sum(n))


    
    

            
