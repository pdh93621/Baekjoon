N, M = list(map(int,input().split()))

times = list(map(int, input().split()))

# sum{[t//time + 1 for time in times]} >= N 이므로 적어도 N이 포함 될 수 있는
# 범위는 0 부터 N*(max_time) 안에 들어있다.

def amusement():
    max_time = N * max(times)
    min_time = 0

    ride_child = 0
    spend_time = 0

    while min_time <= max_time:
        mid = (min_time + max_time) // 2
        num_child = sum([((mid-1) // time + 1) for time in times])
        if num_child < N:
            min_time = mid + 1
            ride_child = num_child
            spend_time = mid
        else:
            max_time = mid - 1

    #print(spend_time)
    #print(ride_child)
    count = 0
    rest = N - ride_child
    for i in range(len(times)):
        if not (spend_time % times[i]):
            count += 1            
            if count == rest:
                return i+1

print(amusement())   
