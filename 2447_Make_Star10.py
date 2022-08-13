stars = []

def rc(n, x, y):
    if n == 1:
        stars[x][y] = '*'
        return

    n //= 3

    for i in range(3):
        for j in range(3):
            if i != 1 or j != 1:
                rc(n, x + n * i, y + n * j)      
        
N = int(input())
stars = [[' ' for _ in range(N)] for _ in range(N)]

rc(N, 0, 0)

for i in stars:
    print(''.join(i))