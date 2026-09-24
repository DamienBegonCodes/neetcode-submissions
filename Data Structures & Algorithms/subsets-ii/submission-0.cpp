#include <unordered_map>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            ++count[num];
        }
        unordered_map<int, int>::iterator it(count.begin());
        unordered_map<int, int>::iterator end(count.end());
        vector<int> solution;
        vector<vector<int>> out;
        backtracking(it, end, solution, out);
        return out;
    }

    void backtracking(unordered_map<int, int>::iterator it, unordered_map<int, int>::iterator end, vector<int> & solution, vector<vector<int>> & out)
    {
        if (it == end)
        {
            out.push_back(solution);
            return;
        }
        int i(0);
        unordered_map<int, int>::iterator copy(it);
        ++copy;
        while (i <= it->second)
        {
            backtracking(copy, end, solution, out);
            solution.push_back(it->first);
            ++i;
        }

        while(!solution.empty() && solution.back() == it->first)
        {
            solution.pop_back();
        }
    }
};
