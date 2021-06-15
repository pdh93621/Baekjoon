N = int(input())
room = []
for i in range(N):
    room.append(list(map(int, input().split())))

room.sort()

conference = []
conference.append(room[0])

for r in room[1:]:
    if conference[-1][1] <= r[0]:
        conference.append(r)
    elif conference[-1][1] >= r[1]:
        conference.pop()
        conference.append(r)

print(len(conference))
    