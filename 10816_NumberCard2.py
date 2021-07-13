N = int(input())
cards = list(map(int, input().split()))
M = int(input())
numbers = list(map(int, input().split()))

cards.sort()

def find_start(number):
    start = 0
    end = N-1
    while start <= end:
        mid = (start + end) // 2
        if cards[mid] >= number:
            end = mid - 1
        else:
            start = mid + 1
    return start

def find_end(number):
    start = 0
    end = N-1
    while start <= end:
        mid = (start + end) // 2
        if cards[mid] > number:
            end = mid - 1            
        else:
            start = mid + 1
    return start

for number in numbers:
    print(find_end(number) - find_start(number), end=' ')