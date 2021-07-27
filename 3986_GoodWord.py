from collections import deque

result = 0
for _ in range(int(input())):
    words = input()
    stack = deque(['C'])
    for word in words:
        if stack[-1] == word:
            stack.pop()
        else:
            stack.append(word)
    if len(stack) == 1:
        result += 1

print(result)
