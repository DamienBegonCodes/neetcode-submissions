class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> out;
        vector<int> solution;
        backtracking(nums, 0, target, out, solution);
        return out;
    }

    void backtracking(vector<int>& nums, int i, int target, vector<vector<int>> & out, vector<int> & solution)
    {
        if (target == 0)
        {
            out.push_back(solution);
            return;
        }
        if (i >= nums.size())
        {
            return;
        }
        int j(0);
        while (j * nums[i] <= target)
        {
            backtracking(nums, i + 1, target - j * nums[i], out, solution);
            solution.push_back(nums[i]);
            ++j;
        }

        while(!solution.empty() && solution.back() == nums[i])
        {
            solution.pop_back();
        }
    }
};
