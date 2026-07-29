// #include <unordered_map>

// class Solution {
// public:
//     bool isAnagram(string & s1, string & s2)
//     {
//         if (s1.length() != s2.length())
//         {
//             return false;
//         }

//         unordered_map<char, int> letters;

//         for (char c : s1)
//         {
//             if (letters.contains(c))
//             {
//                 ++letters[c];
//             }
//             else
//             {
//                 letters.insert({c, 1});
//             }
//         }

//         for (char c : s2)
//         {
//             if (!letters.contains(c))
//             {
//                 return false;
//             }

//             --letters[c];
//             if (letters[c] < 1)
//             {
//                 letters.erase(c);
//             }
//         }

//         return true;
//     }

//     vector<vector<string>> groupAnagrams(vector<string>& strs) 
//     {
//         vector<vector<string>> out;

//         for (string & str : strs)
//         {
//             bool has_broke = false;
//             for (vector<string> & anagram_group : out)
//             {
//                 if (isAnagram(str, anagram_group[0]))
//                 {
//                     anagram_group.push_back(str);
//                     has_broke = true;
//                     break;
//                 }
//             }
            
//             if (!has_broke)
//             {
//                 out.push_back({str});
//             }
//         }

//         return out;
//     }
// };


#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> hash_map;

        for (string & str : strs)
        {
            vector<int> count(26, 0);
            for (char c : str)
            {
                ++count[c - 'a'];
            }

            string key = "";
            for (int num : count)
            {
                key += to_string(num) + ",";
            }

            if (hash_map.contains(key))
            {
                hash_map[key].push_back(str);
            }
            else
            {
                hash_map.insert({key, {str}});
            }

            // hash_map[key].push_back(str);
        }

        vector<vector<string>> out;
        for (auto & entry : hash_map)
        {
            out.push_back({entry.second});
        }
        return out;
    }
};
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> res;
//         for (const auto& s : strs) {
//             vector<int> count(26, 0);
//             for (char c : s) {
//                 count[c - 'a']++;
//             }
//             string key = to_string(count[0]);
//             for (int i = 1; i < 26; ++i) {
//                 key += ',' + to_string(count[i]);
//             }
//             res[key].push_back(s);
//         }
//         vector<vector<string>> result;
//         for (const auto& pair : res) {
//             result.push_back(pair.second);
//         }
//         return result;
//     }
// };