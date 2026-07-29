class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> out(nums.size(), 1);

        int i = 1;
        while (i < nums.size())
        {
            out[i] = out[i - 1] * nums[i - 1];
            ++i;
        }

        int postfix = 1;
        i = nums.size() - 1;
        while (i >= 0)
        {
            out[i] *= postfix;
            postfix *= nums[i];
            --i;
        }

        return out;
    }
};
