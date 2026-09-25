class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int x = 0; x < board.size(); ++x)
        {
            for (int y = 0; y < board[0].size(); ++y)
            {
                if (backtracking(board, word, 0, x, y))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, int i, int x, int y)
    {
        if (i == word.size())
        {
            return true;
        }

        if (x >= board.size() ||
            x < 0 ||
            y >= board[0].size() ||
            y < 0 ||
            board[x][y] != word[i])
        {
            return false;
        }

        char c = board[x][y];
        board[x][y] = '*';

        bool found =    backtracking(board, word, i + 1, x + 1, y) ||
                        backtracking(board, word, i + 1, x - 1, y) ||
                        backtracking(board, word, i + 1, x, y + 1) ||
                        backtracking(board, word, i + 1, x, y - 1);

        board[x][y] = c;
        return found;
    }
};
