class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> out;
        string solution("");
        backtracking(n, 0, solution, out);
        return out;
    }


    void backtracking(int to_open_count, int to_close_count, string & solution, vector<string> & out)
    {
        if (to_open_count == 0 && to_close_count == 0)
        {
            out.push_back(solution);
            return;
        }

        if (to_open_count > 0)
        {
            solution += "(";
            backtracking(to_open_count - 1, to_close_count + 1, solution, out);
            solution.pop_back();
        }

        if (to_close_count > 0)
        {
            solution += ")";
            backtracking(to_open_count, to_close_count - 1, solution, out);
            solution.pop_back();
        }
    }
};
