class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
        out = 0
        visited = {}
        for num in s:
            counter = 0
            num_copy = num
            while num_copy in s:
                if num_copy in visited:
                    counter += visited[num_copy]
                    break
                visited[num_copy] = 1
                num_copy += 1
                counter += 1
            visited[num] = counter
            out = max(counter, out)

        return out