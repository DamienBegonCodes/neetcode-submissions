#include <unordered_map>

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) 
//     {
//         unordered_map<int, int> to_target;
//         int n = nums.size();

//         for (int i = 0; i < n; ++i)
//         {
//             if (to_target.contains(nums[i]))
//             {
//                 return {to_target[nums[i]], i};
//             }
//             else
//             {
//                 to_target.insert({target - nums[i], i});
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if (prevMap.count(diff)) {
                vector<int> indexes = {prevMap[diff], i}; 
                return indexes;
            }
            prevMap.insert({nums[i], i});
        }
        return {};
    }
};
