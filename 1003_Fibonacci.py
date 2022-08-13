T = int(input())
test = []
for _ in range(T):
    test.append(int(input()))

N = max(test)

num_zero = [1,0]
num_one = [0,1]

for n in range(2,N+1):
    num_zero.append(num_zero[n-1] + num_zero[n-2])
    num_one.append(num_one[n-1] + num_one[n-2])

for t in test:
    print(num_zero[t], num_one[t])

print(T)
print(num_zero)
print(num_one) 