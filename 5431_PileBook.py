from collections import deque

T = int(input())

def good(l_book,n_book):
    for i in range(n_book-1):        
        if l_book[i] > l_book[i+1]:
            l_book.appendleft(l_book[i+1])            
            del l_book[i+2]            
            return True
    return False

for t in range(T):
    n_book = int(input())
    l_book = deque(map(int,input().split()))
    count = 0
    start = 0
    
    while good(l_book, n_book):
        count += 1

    print(count)
