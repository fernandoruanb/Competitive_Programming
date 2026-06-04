class Solution(object):
    def missingNumber(self, nums):
       size = len(nums)
       res = size * (size + 1) // 2
       total = 0

       for n in nums:
            total += n
       return res - total  

'''
if __name__ == "__main__":
	sol = Solution()
	nums = [3, 0 ,1]
	result = sol.missingNumber(nums) 
	print(result)
'''
