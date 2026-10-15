#include <list>

class Solution {

    const vector<string> letters = 
    {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")
        {
            return {};
        }
        vector<string> out;
        string solution("");
        backtracking(0, digits, out, solution);
        return out;
    }

    void backtracking(int i, string & digits, vector<string> & out, string & solution)
    {
        if (i >= digits.size())
        {
            out.push_back(solution);
            return;
        }
        string chars(letters[digits[i] - '0']);

        for (char c : chars)
        {
            solution.push_back(c);
            backtracking(i + 1, digits, out, solution);
            solution.pop_back();
        }
    }
};
