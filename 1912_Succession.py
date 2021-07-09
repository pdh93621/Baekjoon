N = int(input())
seq = list(map(int, input().split()))

for n in range(1,N):
    if seq[n-1] > 0:
        seq[n] += seq[n-1]

print(max(seq))