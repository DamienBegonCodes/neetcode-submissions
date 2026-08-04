class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int out = 0;

        vector<int>::iterator left(heights.begin());
        vector<int>::iterator right(heights.end() - 1);

        while(left != right)
        {
            int width = right - left;
            int height;
            if (*left < *right)
            {
                height = *left;
                ++left;
            }
            else
            {
                height = *right;
                --right;
            }

            if (width * height > out)
            {
                out = width * height;
            }
        }

        return out;
    }
};
