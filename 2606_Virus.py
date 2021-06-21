from collections import deque

computer = int(input())
lines = int(input())

graph = []
for l in range(lines):
    graph.append(list(map(int,input().split())))

queue = deque([1])
visited = [0 for i in range(computer)]

def spread_virus(graph, visited, queue):
    temp = queue.popleft()
    remove_list = []
    for g in graph:
        if temp in g:
            remove_list.append(g)
            g.remove(temp)
            spread = g[0]
            if not visited[spread-1]:
                visited[spread-1] = 1
                queue.append(spread)
    for r in remove_list:
        graph.remove(r)

while queue:
    spread_virus(graph, visited, queue)
    
print(sum(visited))
