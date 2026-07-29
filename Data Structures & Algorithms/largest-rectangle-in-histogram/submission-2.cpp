#include <stack>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int out = 0;
        stack<pair<int, int>> s;
        int n = heights.size();


        for (int i = 0; i < n; ++i)
        {
            if (s.empty())
            {
                s.push({heights[i], i});
            }
            else
            {
                if (s.top().first > heights[i])
                {
                    int start;
                    while(!s.empty() && s.top().first > heights[i])
                    {
                        start = s.top().second;
                        int width = i - start;
                        int area = width * s.top().first;
                        if (area > out)
                        {
                            out = area;
                        }
                        s.pop();
                    }
                    
                    s.push({heights[i], start});
                }
                else if (heights[i] > s.top().first)
                {
                    s.push({heights[i], i});
                }
            }
        }

        while(!s.empty())
        {
            int start = s.top().second;
            int width = n - start;
            int area = width * s.top().first;
            if (area > out)
            {
                out = area;
            }
            s.pop();
        }

        return out;
    }
};
