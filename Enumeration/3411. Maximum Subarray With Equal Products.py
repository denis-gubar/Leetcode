class Solution(object):
    def gcd(self, a, b ):
        while b:
            a , b = b , a % b
        return a
    def maxLength(self, nums):
        N = len(nums)
        for length in range(N, 0, -1):
            for start in range(0, N - length + 1):
                a = nums[start]
                b = a
                x = a
                for i in range(start + 1, start + length):
                    a = a * nums[i] // self.gcd(a, nums[i])
                    b = self.gcd(b, nums[i])
                    x = x * nums[i]
                if x == a * b:
                    return length
        return 0
        