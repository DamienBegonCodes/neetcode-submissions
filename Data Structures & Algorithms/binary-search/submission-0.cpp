class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l(0), r(nums.size() - 1), mid(l + (r - l) / 2);

        while (l <= r)
        {
            if (target < nums[mid])
            {
                r = mid - 1;
            }
            else if (target > nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
            mid = l + (r - l) / 2;
        }
        return -1;
    }
};
