#include <unordered_map>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        unordered_map<int, int> candidates_hm;
        for (int candidate : candidates)
        {
            ++candidates_hm[candidate];
        }
        unordered_map<int, int>::iterator it(candidates_hm.begin());
        vector<vector<int>> out;
        vector<int> solution;
        backtracking(it, candidates_hm.end(), target, out, solution);
        return out;
    }

    void backtracking(unordered_map<int, int>::iterator it, unordered_map<int, int>::iterator end, int target, vector<vector<int>> & out, vector<int> & solution)
    {
        if (target == 0)
        {
            out.push_back(solution);
            return;
        }
        if (it == end)
        {
            return;
        }
        int j(0);
        unordered_map<int, int>::iterator next(it);
        ++next;
        while (j * it->first <= target && j <= it->second)
        {
            backtracking(next, end, target - j * it->first, out, solution);
            solution.push_back(it->first);
            ++j;
        }

        while(!solution.empty() && solution.back() == it->first)
        {
            solution.pop_back();
        }
    }
};


