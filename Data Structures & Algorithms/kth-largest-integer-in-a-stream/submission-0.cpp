#include <vector>
#include <queue>
#include <functional>

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> k_largest;
    int k;

    KthLargest(int k, vector<int>& nums) : k(k), k_largest()
    {
        for (int num : nums)
        {
            k_largest.push(num);
            if (k_largest.size() > k)
            {
                k_largest.pop();
            }
        }
    }
    
    int add(int val) 
    {
        k_largest.push(val);
        if (k_largest.size() > k)
        {
            k_largest.pop();
        }
        return k_largest.top();
    }
};
