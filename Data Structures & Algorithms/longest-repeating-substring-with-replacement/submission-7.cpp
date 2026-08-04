#include <unordered_map>
#include <vector>

 class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int out(0), n(s.length());
        unordered_map<char, int> hm;

        int l(0), r(0);
        int max_f(0);
        while(r < n)
        {
            if (!hm.contains(s[r]))
            {
                hm[s[r]] = 0;
            }
            max_f = max(max_f, ++hm[s[r]]);
            int length = r - l + 1;
            if (length - max_f <= k)
            {
                out = max(out, length);
                ++r;
            }
            else
            {
                --hm[s[l]];
                --hm[s[r]];
                ++l;
            }
        }
        return out;
    }
};
