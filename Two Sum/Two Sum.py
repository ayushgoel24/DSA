class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        container = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in container:
                return [i, container[complement]]
            container[nums[i]] = i
        return []