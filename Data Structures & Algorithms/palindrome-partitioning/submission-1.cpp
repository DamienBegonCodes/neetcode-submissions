class Solution {
public:
    bool is_palindrome(const string & s)
    {
        int l(0), r(s.length() - 1);
        while(l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> out;
        vector<string> solution;
        backtracking(s, solution, out);

        return out;
    }

    void backtracking(const string & s, vector<string> & solution, vector<vector<string>> & out)
    {
        if (s.length() == 0)
        {
            out.push_back(solution);
            return;
        }
        
        int i(1);
        while (i <= s.length())
        {
            if (is_palindrome(s.substr(0, i)))
            {
                solution.push_back(s.substr(0, i));
                backtracking(s.substr(i), solution, out);
                solution.pop_back();
            }
            ++i;
        }
    }
};
