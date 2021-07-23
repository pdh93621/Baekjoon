T = int(input())

def OX(string):
    result = 0
    num = 0    
    for ox in string:
        if ox == 'X':
            num = 0
        else:
            num = num + 1   
        result = result + num
    print(result)

for _ in range(T):
    OX(input())