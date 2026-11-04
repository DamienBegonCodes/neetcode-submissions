class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
        out = 0
        starts = []
        for num in s:
            if num - 1 not in s:
                starts.append(num)

        out = 0
        for num in starts:
            counter = 0
            while num in s:
                counter += 1
                num += 1
            out = max(counter, out)
        return out