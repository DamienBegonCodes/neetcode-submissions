

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> out;
        vector<int> solution(nums.size(), -11);

        backtracking(nums, 0, out, solution);
        return out;
    }

    void backtracking(vector<int>& nums, int i, vector<vector<int>> & out, vector<int> & solution)
    {
        if (i == nums.size())
        {
            out.push_back(solution);
            return;
        }
        int j(0);
        while (j < solution.size())
        {
            if (solution[j] == -11)
            {
                solution[j] = nums[i];
                backtracking(nums, i + 1, out, solution);
                solution[j] = -11;
            }
            ++j;
        }
    }
};
