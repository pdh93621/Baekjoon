computer = int(input())
line = int(input())

graph = []
for l in range(line):
    graph.append(list(map(int,input().split())))

visited = [0 for i in range(computer)]

print(visited)
