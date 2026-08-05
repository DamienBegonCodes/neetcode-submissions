#include <unordered_map>

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n(s.size()), m(t.size());
        if (n < m)
        {
            return "";
        }
        string out("");
        unordered_map<char, int> count_t, count_window;

        for (char c : t)
        {
            ++count_t[c];
        }

        int matches_required(count_t.size());
        int l(0), r(0);
        int matches(0);

        while (r < n)
        {
            if (count_t.contains(s[r]))
            {
                ++count_window[s[r]];
                if (count_window[s[r]] == count_t[s[r]])
                {
                    ++matches;
                }
            }

            while(matches == matches_required)
            {
                if (out == "" || r - l + 1 < out.size())
                {
                    out = s.substr(l, r - l + 1);
                }
                
                if (count_t.contains(s[l]))
                {
                    if (count_window[s[l]] == count_t[s[l]])
                    {
                        --matches;
                    }
                    --count_window[s[l]];
                }
                ++l;
            }
            ++r;
        }
        return out;
    }
};
