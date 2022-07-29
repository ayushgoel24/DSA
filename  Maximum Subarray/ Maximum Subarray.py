class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        max_so_far = nums[0]
        curr_value = nums[0]
        for i in range(1, len(nums)):
            curr_value = max(nums[i], curr_value + nums[i])
            max_so_far = max(max_so_far, curr_value)
        return max_so_far
        