#include <functional>
#include <stack>

class Solution {
public:
    unordered_map<string, function<int(int, int)>> operators =
    {
        {"+", [](int a, int b) {return a + b;}},
        {"-", [](int a, int b) {return a - b;}},
        {"*", [](int a, int b) {return a * b;}},
        {"/", [](int a, int b) {return a / b;}}
    };
    int evalRPN(vector<string>& tokens) 
    {
        if (tokens.size() == 1)
        {
            return stoi(tokens[0]);
        }

        stack<int> s;

        for (string & token : tokens)
        {
            if (operators.contains(token))
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(operators[token](a, b));
            }
            else
            {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
