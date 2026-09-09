#include <string>
#include <unordered_map>

class TrieNode
{
public:
    char c;
    std::unordered_map<char, TrieNode*> next;
    bool isEndOfWord;

    TrieNode() : c(), next(), isEndOfWord(false) {};
    TrieNode(char c) : c(c), next(), isEndOfWord(false) {};
};


class PrefixTree {
public:
    TrieNode * root;
    
    PrefixTree() : root(new TrieNode) {}
    
    void insert(string word)
    {
        TrieNode * curr(root);
        for (char c : word)
        {
            if (!curr->next.contains(c))
            {
                curr->next[c] = new TrieNode(c);
            }

            curr = curr->next[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode * curr(this->root);
        for (char c : word)
        {
            if (!curr->next.contains(c))
            {
                return false;
            }
            curr = curr->next[c];
        }

        if (!curr->isEndOfWord)
        {
            return false;
        }

        return true;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode * curr(this->root);
        for (char c : prefix)
        {
            if (!curr->next.contains(c))
            {
                return false;
            }
            curr = curr->next[c];
        }

        return true;
    }
};
