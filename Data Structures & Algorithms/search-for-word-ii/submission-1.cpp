class TrieNode 
{
public:
    vector<TrieNode *> next;
    int index;

    TrieNode() : next(26, nullptr), index(-1) {}
};

class Trie 
{
public:
    TrieNode * root;

    void addWord(string & word, int i)
    {
        TrieNode * curr(root);
        for (char c : word)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->index = i;
    }

    Trie() : root(new TrieNode) {}
};

#include <utility>

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie trie;
        for (int i = 0; i < words.size(); ++i)
        {
            trie.addWord(words[i], i);
        }

        int n(board.size()), m(board[0].size());
        vector<string> out;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dfs(board, out, trie.root, i, j, words);
            }
        }
        return out;
    }

    void dfs(vector<vector<char>>& board, vector<string>& out, TrieNode * node, int i, int j, vector<string>& words)
    {
        if (i < 0 || 
            j < 0 || 
            i >= board.size() || 
            j >= board[0].size() ||
            board[i][j] == '*' ||
            node->next[board[i][j] - 'a'] == nullptr)
        {
            return;
        }
        
        char c(board[i][j]);
        board[i][j] = '*';
        TrieNode * next = node->next[c - 'a'];
        if (next->index >= 0)
        {
            out.push_back(words[next->index]);
            next->index = -1;
        }

        dfs(board, out, next, i + 1, j, words);
        dfs(board, out, next, i - 1, j, words);
        dfs(board, out, next, i, j + 1, words);
        dfs(board, out, next, i, j - 1, words);

        board[i][j] = c;
    }
};
