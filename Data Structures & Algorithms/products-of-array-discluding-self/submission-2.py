class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        out = [1] * len(nums)

        for i in range(0, len(nums) - 1):
            prod *= nums[i]
            out[i + 1] *= prod

        prod = 1
        for i in range(len(nums) - 1, 0, -1):
            prod *= nums[i]
            out[i - 1] *= prod

        return out