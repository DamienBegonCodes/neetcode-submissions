#include <unordered_map>
#include <vector>

//  class Solution {
// public:
//     int characterReplacement(string s, int k) 
//     {
//         int out(0), n(s.length());
//         unordered_map<char, int> hm;

//         int l(0), r(0);
//         int max_f(0);
//         while(r < n)
//         {
//             if (!hm.contains(s[r]))
//             {
//                 hm[s[r]] = 0;
//             }
//             max_f = max(max_f, ++hm[s[r]]);
//             int length = r - l + 1;
//             while (length - max_f > k && l <= r)
//             {
//                 // cerr << "HAAA" << endl;
//                 --hm[s[l]];
//                 // cerr << "HAAA" << endl;
//                 // cerr << endl;

//                 ++l;
//             }
//             out = max(out, length);
//             ++r;
//         }
//         return out;
//     }
// };

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
