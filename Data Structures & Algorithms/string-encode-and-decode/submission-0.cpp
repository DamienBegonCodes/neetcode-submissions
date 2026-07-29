class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string out = "";

        for (auto & str : strs)
        {
            out.append(to_string(str.length()) + "#");
            out.append(str);
        }

        return out;
    }

    vector<string> decode(string s) 
    {
        vector<string> out;

        for (int i = 0; i < s.length(); ++i)
        {
            int num_start = i;

            while (s[i] != '#')
            {
                ++i;
            }

            int n = stoi(s.substr(num_start, i - num_start));

            out.push_back(s.substr(i + 1, n));
            i += n;
        }

        return out;
    }
};
