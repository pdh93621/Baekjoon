from collections import deque

class RD:
    def __init__(self,nums):
        self.reversed = False
        self.nums = nums
    
    def rd(self, x):
        if nums:
            if x == 'R':
                self.reversed = not self.reversed
            else:
                if self.reversed:
                    self.nums.pop()
                else:
                    self.nums.popleft()

    def prt(self):
        if nums:
            if self.reversed:
                self.nums.reverse()
            print('[' + ','.join(self.nums) + ']\n')
        else:
            print('error')

T = int(input())

for _ in range(T):
    rdlist = input()
    len_list = int(input())
    nums = input()
    if len(nums) > 2:
        nums = deque(nums[1:-1].split(','))

        rdfunc = RD(nums)
        for i in rdlist:
            rdfunc.rd(i)
        rdfunc.prt()
    else:
        print('error')