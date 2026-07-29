#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<vector<unordered_set<char>>> sets(3, std::vector<unordered_set<char>>(9, unordered_set<char>()));

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char elem = board[i][j];
                if (elem == '.')
                {
                    continue;
                }

                // Row
                if (sets[0][i].contains(elem))
                {
                    return false;
                }
                sets[0][i].insert(elem);

                // Col
                if (sets[1][j].contains(elem))
                {
                    return false;
                }
                sets[1][j].insert(elem);

                // Box
                int index = 3 * (i / 3) + j / 3;
                if (sets[2][index].contains(elem))
                {
                    return false;
                }
                sets[2][index].insert(elem);
            }
        }

        return true;
    }
};
