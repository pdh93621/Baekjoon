N = int(input())

def hanoi(N,a,b,c):
    if N == 0:
        return 'complete'
    elif N == 1:
        print(a, c)
    else:
        hanoi(N-1,a,c,b)
        print(a,c)
        hanoi(N-1,b,a,c)

def num_hanoi(N):
    if N == 1:
        return 1
    else:
        return 2 * num_hanoi(N-1) + 1

print(num_hanoi(N))
if N <= 20:
    hanoi(N,1,2,3)


