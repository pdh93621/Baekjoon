T = int(input())

tests = []

for _ in range(T):
    tests.append(int(input()))

t = max(tests)
if t < 6:
    seq = [0]*6
else:
    seq = [0] * (t+1)

seq[1] = 1
seq[2] = 1
seq[3] = 1
seq[4] = 2
seq[5] = 2
n = 6

while n <= t:
    seq[n] = seq[n-1] + seq[n-5]
    n += 1

for test in tests:
    print(seq[test])