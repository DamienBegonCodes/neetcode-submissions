#include <functional>
#include <stack>

class Solution {
public:
    unordered_map<char, function<int(int, int)>> operators =
    {
        {'+', [](int a, int b) {return a + b;}},
        {'-', [](int a, int b) {return a - b;}},
        {'*', [](int a, int b) {return a * b;}},
        {'/', [](int a, int b) {return a / b;}}
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
            if (token.length() == 1 && operators.contains(token[0]))
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(operators[token[0]](a, b));
            }
            else
            {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
