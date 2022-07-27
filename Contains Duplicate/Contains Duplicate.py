class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        container = {}
        for num in nums:
            if num in container:
                return True
            container[num] = 1
        return False