#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());

        int out = 0;

        for (int num : nums)
        {
            if (s.contains(num - 1))
            {
                continue;
            }

            int next = num + 1;
            while(s.contains(next))
            {
                ++next;
            }
            if (out < next - num)
            {
                out = next - num;
            }
        }

        return out;
    }
};
