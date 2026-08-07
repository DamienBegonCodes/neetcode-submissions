#include <unordered_map>
#include <vector>

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> time_map;

    TimeMap() : time_map() {}
    
    void set(string key, string value, int timestamp) 
    {
        int n = time_map[key].size();
        if (n == 0 || time_map[key][n - 1].first < timestamp)
        {
            time_map[key].push_back({timestamp, value});
        }   
    }
    
    string get(string key, int timestamp) 
    {
        if (!time_map.contains(key))
        {
            return "";
        }
        
        if (time_map[key].begin()->first > timestamp)
        {
            return "";
        }
        else if (time_map[key].rbegin()->first <= timestamp)
        {
            return time_map[key].rbegin()->second;
        }
        else
        {
            int n(time_map[key].size()) ,l(0), r(n - 1), bi(l);

            while (l <= r)
            {
                int m((l + r) / 2);
                if (time_map[key][m].first > timestamp)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                    bi = m;
                }
            }

            return time_map[key][bi].second;
        }
    }
};
