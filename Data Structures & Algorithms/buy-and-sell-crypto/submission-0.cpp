class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int out(0);
        int current_min(100);
        for (int price : prices)
        {
            if (price < current_min)
            {
                current_min = price;
            }
            else if (price - current_min > out)
            {
                out = price - current_min;
            }
        }

        return out;
    }
};
