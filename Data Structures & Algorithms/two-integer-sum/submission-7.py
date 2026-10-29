class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i in range(len(nums)):
            if nums[i] in d:
                return [d[nums[i]], i]
            
            d[target - nums[i]] = i
        