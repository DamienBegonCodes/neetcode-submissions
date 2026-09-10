#include<vector>
#include<stack>
#include<utility>

class TrieNode
{
public:
    vector<TrieNode*> next;
    bool isWord;

    TrieNode() : next(26, nullptr), isWord(false) {};
};

class WordDictionary {
public:
    TrieNode * root;
    
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) 
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
        curr->isWord = true;    
    }
    
    bool search(string word) 
    {
        stack<pair<TrieNode*, int>> s({{root, 0}});
        while (!s.empty())
        {
            TrieNode * node(s.top().first);
            int i(s.top().second);
            s.pop();
            if (i == word.length())
            {
                if (node->isWord)
                {
                    return true;
                }
                continue;
            }

            if (word[i] == '.')
            {
                for (TrieNode * next_node : node->next)
                {
                    if (next_node != nullptr)
                    {
                        s.push({next_node, i + 1});
                    }
                }
            }
            else
            {
                if (node->next[word[i] - 'a'] != nullptr)
                {
                    s.push({node->next[word[i] - 'a'], i + 1});
                }
            }
        }
        return false;
    }
};
