#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) 
    {
        if (s.length() % 2)
        {
            return false;
        }

        string::iterator it = s.begin();
        stack<char> opening_brackets;
        unordered_map<char, char> corresponding_brackets = 
        {
            {'(', ')'}, 
            {'[', ']'},
            {'{', '}'}
        };

        while(it != s.end())
        {
            if (*it == '(' || *it == '[' || *it == '{')
            {
                opening_brackets.push(*it);
            }
            else
            {
                if (opening_brackets.empty())
                {
                    return false;
                }
                if (corresponding_brackets[opening_brackets.top()] != *it)
                {
                    return false;
                }

                opening_brackets.pop();
            }

            ++it;
        }
        if (!opening_brackets.empty())
        {
            return false;
        }
        return true;
    }
};
