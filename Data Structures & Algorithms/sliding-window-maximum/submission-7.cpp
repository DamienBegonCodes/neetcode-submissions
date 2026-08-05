#include <map>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n(nums.size());
        vector<int> out(n - k + 1);
        map<int, int> window_count;

        for (int i = 0; i < k; ++i)
        {
            ++window_count[nums[i]];
        }

        int l(0), r(k - 1);
        while(r < n - 1)
        {
            out[l] = window_count.rbegin()->first;

            --window_count[nums[l]];

            ++r;
            ++window_count[nums[r]];
            if (window_count[nums[l]] == 0)
            {
                window_count.erase(nums[l]);
            }

            ++l;
        }
        out[l] = window_count.rbegin()->first;

        return out;
    }
};
