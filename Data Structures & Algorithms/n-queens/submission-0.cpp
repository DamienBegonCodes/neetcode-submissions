class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> out;
        vector<string> line(n, ".");
        vector<string> solution;
        backtracking(out, line, solution, 1);

        return out;
    }

    void backtracking(vector<vector<string>> & out, vector<string> & line, vector<string> & solution, int line_nb)
    {
        int n(line.size());
        if (line_nb > n)
        {
            out.push_back(solution);
            return;
        }

        vector<string> next_line_base(n, "");
        for (int i(0); i < n; ++i)
        {
            for (char c : line[i])
            {
                switch(c)
                {
                    case '<':
                        if (i - 1 >= 0)
                        {
                            next_line_base[i - 1].push_back('<');
                        }
                        break;
                    case '>':
                        if (i + 1 < n)
                        {
                            next_line_base[i + 1].push_back('>');
                        }
                        break;
                    case 'X':
                        next_line_base[i].push_back('X');
                        break;
                    case '.':
                    default:
                        break;
                }
            }
        }
        string line_solution;

        for (int i(0); i < n; ++i)
        {
            string s(line[i]);
            if (s.size() == 1 && s[0] == '.')
            {
                line_solution = string(n, '.');
                line_solution[i] = 'Q';

                vector<string> next_line(next_line_base);
                next_line[i].push_back('X');
                if (i - 1 >= 0)
                {
                    next_line[i - 1].push_back('<');
                }
                if (i + 1 < n)
                {
                    next_line[i + 1].push_back('>');
                }

                for (string & next_line_s : next_line)
                {
                    if (next_line_s.empty())
                    {
                        next_line_s = ".";
                    }
                }

                solution.push_back(line_solution);
                backtracking(out, next_line, solution, line_nb + 1);
                solution.pop_back();
            }
        }
    }
};
