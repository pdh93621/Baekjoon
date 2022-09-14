chess = []

def matchingBW():
    n = 0
    for i in range(8):
        for j in range(8):
            n += ((-1)**(i + j) != chess[i][j])
    return n

def matchingH(i):
    if not i: return 0
    i = i - 1
    n = 0
    for j in range(8):
        n -= ((-1)**(i + j) != chess[i][j])
        n += ((-1)**(i + j) != chess[i + 8][j])
    return n

def matchingV(I, j):
    if not j: return 0
    j = j - 1
    m = 0
    for i in range(I, I + 8):
        m -= ((-1)**(i + j) != chess[i][j])
        m += ((-1)**(i + j) != chess[i][j + 8])
    return m

N, M = map(int, input().split())

for _ in range(N):
    temp = []
    raw = input()
    for r in raw: temp.append((r == "W") - (r == "B"))
    chess.append(temp)

result = 100000

for i in range(N - 7):
    if not i: init_v = matchingBW()
    init_v += matchingH(i)
    for j in range(M - 7):
        if not j: temp_v = init_v
        temp_v += matchingV(i, j)
        result = min(result, temp_v, 64 - temp_v)

print(result)