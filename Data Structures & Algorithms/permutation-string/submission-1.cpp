#include <unordered_map>

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        unordered_map<char, int> count;
        for (char c : s1)
        {
            ++count[c];
        }

        int l = 0;
        int r = s1.size() - 1;

        while(r < s2.size())
        {
            unordered_map<char, int> copy(count);

            int j = r;
            bool broke = false;
            while(j >= l)
            {
                if (copy.contains(s2[j]))
                {
                    if (--copy[s2[j]] <= 0)
                    {
                        copy.erase(s2[j]);
                    }
                    --j;
                }
                else
                {
                    broke = true;
                    break;
                }
            }

            if (!broke)
            {
                return true;
            }
            l = j + 1;
            r = l + s1.size() - 1;
        }
        return false;
    }
};
