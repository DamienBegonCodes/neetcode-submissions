class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> out(2);

        int i = 0;
        int j = numbers.size() - 1;

        while(true)
        {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
            {
                ++i;
            }
            else if (sum > target)
            {
                --j;
            }
            else
            {
                out[0] = ++i;
                out[1] = ++j;
                return out;
            }
        }
    }
};
