class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> out({{}});

        int i(0), n(nums.size());
        while (i < n)
        {
            int j(0), out_size(out.size());
            while(j < out_size)
            {
                vector<int> copy(out[j]);
                copy.push_back(nums[i]);
                out.push_back(copy);
                ++j;
            }
            ++i;
        }

        return out;
    }

    // void subsets_recursive(vector<int>& nums, vector<vector<int>>& out, )
    // {
    //     out.push_back(nums);

    //     int i(0), n(nums);
    //     while(i)
    // }
};
