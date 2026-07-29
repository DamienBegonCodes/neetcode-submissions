#include <map>
#include <float.h>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int out = 1;
        int n = position.size();

        map<int, int> car_info;

        for (int i = 0; i < n; ++i)
        {
            car_info.insert({position[i], speed[i]});
        }

        vector<double> time(n);
        int i = 0;            
        for (auto & car : car_info)
        {
            time[i] = (double) (target - car.first) / (double) car.second;
            cout << time[i] << endl;
            ++i;
        }

        double fleet_head_time = time[n - 1];
        for (int j = n - 1; j >= 0; --j)
        {
            if (time[j] > fleet_head_time)
            {
                ++out;
                fleet_head_time = time[j];
            }
        }

        return out;
    }
};
