class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        prefix = [1]

        for i in range(0, len(nums) - 1):
            prod *= nums[i]
            prefix.append(prod)

        prod = 1
        suffix = [1] * len(nums)
        for i in range(len(nums) - 1, 0, -1):
            prod *= nums[i]
            suffix[i - 1] = prod
        
        out = []
        for i in range(len(nums)):
            out.append(prefix[i] * suffix[i])

        return out

        
