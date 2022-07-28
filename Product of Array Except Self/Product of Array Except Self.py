class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answers = [1] * len(nums)
        
        temp = 1
        for i in range(len(nums)):
            answers[i] = temp
            temp *= nums[i]
        
        temp = 1
        for i in range(len(nums) -1, -1, -1):
            answers[i] *= temp
            temp *= nums[i]
        
        return answers