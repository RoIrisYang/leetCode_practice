class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:        
        output = []
        for n, num in enumerate(nums):
            for j in range(n+1, len(nums)):                
                if num + nums[j] == target:
                        return [n, j]