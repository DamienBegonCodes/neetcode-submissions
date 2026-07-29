#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> to_target;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int val = nums[i];
            if (to_target.contains(val))
            {
                return {to_target[val], i};
            }
            else
            {
                to_target.insert({target - val, i});
            }
        }
        return {};
    }
};