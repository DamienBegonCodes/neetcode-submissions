#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> out(n, 0);

        stack<pair<int, int>> temps;

        int i = 0;
        while (i < n)
        {
            if (!temps.empty() && temperatures[i] > temps.top().first)
            {
                out[temps.top().second] = i - temps.top().second;
                temps.pop();
                continue;
            }

            temps.push({temperatures[i], i});

            ++i;
        }

        return out;
    }
};
