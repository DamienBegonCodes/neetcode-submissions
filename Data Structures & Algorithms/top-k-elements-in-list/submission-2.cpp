#include <unordered_map>

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) 
//     {
//         unordered_map<int, int> hash_map;

//         for (int num : nums)
//         {
//             if (!hash_map.contains(num))
//             {
//                 hash_map.insert({num, 0});
//             }

//             ++hash_map[num];
//         }

//         vector<int> keys(hash_map.size(), 0);
//         vector<int> count(hash_map.size(), 0);

//         int i = 0;
//         for (auto & elem : hash_map)
//         {
//             keys[i] = elem.first;
//             count[i] = elem.second;
//             ++i;
//         }

//         vector<int> out(k, 0);


//         for (int j = 0; j < k; ++j)
//         {
//             int max = -1001;
//             int key = -1;
//             int argmax = -1;
            
//             for (int l = 0; l < count.size(); ++l)
//             {

//                 if (max < count[l])
//                 {
//                     max = count[l];
//                     key = keys[l];
//                     argmax = l;
//                 }
//             }
//             out[j] = key;
//             count[argmax] = -1001;
//         }

//         return out;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            ++count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
