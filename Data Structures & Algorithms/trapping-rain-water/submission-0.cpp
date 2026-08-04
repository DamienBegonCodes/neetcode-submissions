class Solution {
public:
    int trap(vector<int>& height)
    {
        int out = 0;

        vector<int>::iterator l(height.begin());
        vector<int>::iterator r(height.end() - 1);

        int max_l(*l);
        int max_r(*r);

        while (l != r)
        {
            if (max_l < max_r)
            {
                ++l;
                max_l = max(*l, max_l);
                out += max_l - *l;
            }
            else
            {
                --r;
                max_r = max(*r, max_r);
                out += max_r - *r;
            }

        }

        return out;
    }
};
