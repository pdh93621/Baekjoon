seq = [int(input()) for _ in range(int(input()))]

def find_prime_num(num):
    prime = [True for _ in range(num)]
    for i in range(2,num):
        if prime[i]:
            for j in range(2*i, num, i):
                prime[j] = False
    return prime

def goldbach(num,prime):
    for i in range(num // 2, 0, -1):
        if prime[i] and prime[num-i]:
            print(i, num-i)
            return        


prime = find_prime_num(max(seq))
for num in seq:
    goldbach(num, prime)