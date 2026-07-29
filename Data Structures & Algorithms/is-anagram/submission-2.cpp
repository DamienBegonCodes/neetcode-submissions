#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> char_count;
        for (char c : s)
        {
            if (char_count.contains(c))
            {
                ++char_count[c];
            }
            else
            {
                char_count.insert({c, 1});
            }
        }

        for (char c : t)
        {
            if (!char_count.contains(c))
            {
                return false;
            }
            else
            {
                --char_count[c];
                if (char_count[c] == 0)
                {
                    char_count.erase(c);
                }
            }
        }
        if (!char_count.empty())
        {
            return false;
        }
        return true;
    }
};
