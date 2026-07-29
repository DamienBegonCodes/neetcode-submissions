#include <unordered_map>

class Solution {
public:
    bool isAnagram(string & s1, string & s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }

        unordered_map<char, int> letters;

        for (char c : s1)
        {
            if (letters.contains(c))
            {
                ++letters[c];
            }
            else
            {
                letters.insert({c, 1});
            }
        }

        for (char c : s2)
        {
            if (!letters.contains(c))
            {
                return false;
            }

            --letters[c];
            if (letters[c] < 1)
            {
                letters.erase(c);
            }
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> out;

        for (string & str : strs)
        {
            bool has_broke = false;
            for (vector<string> & anagram_group : out)
            {
                if (isAnagram(str, anagram_group[0]))
                {
                    anagram_group.push_back(str);
                    has_broke = true;
                    break;
                }
            }
            
            if (!has_broke)
            {
                out.push_back({str});
            }
        }

        return out;
    }
};
