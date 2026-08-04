#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int out(0), n(s.length()), begin(0);
        unordered_map<char, int> chars;
        for (int i = 0; i < n; ++i)
        {
            if (chars.contains(s[i]))
            {
                if (chars[s[i]] >= begin)
                {
                    out = max(out, i - begin);
                    begin = chars[s[i]] + 1;
                }
                chars[s[i]] = i;
            }
            else
            {
                chars.insert({s[i], i});
            }
        }
        out = max(out, n - begin);
        return out;
    }
};
