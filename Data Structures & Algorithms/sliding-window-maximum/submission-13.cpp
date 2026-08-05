#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n(nums.size());
        vector<int> out(n - k + 1);
        deque<pair<int, int>> deq;

        int l(0), r(k - 1);
        for (int i = 0; i <= r; ++i)
        {
            if (deq.empty())
            {
                deq.push_back({nums[i], i});
            }
            else
            {
                while (!deq.empty() && nums[i] >= deq.back().first)
                {
                    deq.pop_back();
                }

                deq.push_back({nums[i], i});
            }
        }

        out[l] = deq.front().first;

        while(r < n - 1)
        {
            ++l;
            if (l > deq.front().second)
            {
                deq.pop_front();
            }

            ++r;
            while (!deq.empty() && nums[r] >= deq.back().first)
            {
                deq.pop_back();
            }
            deq.push_back({nums[r], r});
            out[l] = deq.front().first;
        }
        return out;
    }
};
