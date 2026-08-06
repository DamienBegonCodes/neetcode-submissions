class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int n(nums.size()), out;
        if (nums[0] < nums[n - 1])
        {
            return nums[0];
        }    

        int l(0), r(n - 1);
        while (l <= r)
        {
            int mid((l + r) / 2);

            if (nums[mid] <= nums[r])
            {
                out = min(out, nums[mid]);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return out;
    }
};
