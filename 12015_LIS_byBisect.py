def find_loc(seq,number):
    start = 0
    end = len(seq) - 1

    while start <= end:
        mid = (start + end) // 2

        if seq[mid] >= number:
            end = mid - 1
        else:
            start = mid + 1
    
    return start

N = int(input())
A = list(map(int, input().split()))

seq = [0]

for num in A:
    if num > seq[-1]:
        seq.append(num)
    else:
        seq[find_loc(seq, num)] = num

print(len(seq)-1)