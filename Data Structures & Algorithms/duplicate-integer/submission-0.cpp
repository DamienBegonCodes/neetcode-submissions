#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
        {
            if (s.contains(nums[i]))
            {
                return true;
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        return false;
    }
};