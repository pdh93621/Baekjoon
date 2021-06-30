N = int(input())
array = list(map(int, input().split()))
array.sort()

def find_num(number):
    start = 0
    end = N - 1
    
    while start <= end:
        mid = (start + end) // 2

        if array[mid] == number:
            return 1

        elif array[mid] > number:
            end = mid - 1

        else:
            start = mid + 1
    
    return 0

M = int(input())
numbers = list(map(int, input().split()))

for number in numbers:
    print(find_num(number))