// #include <functional>
#include <stack>

// class Solution {
// public:
//     unordered_map<string, function<int(int, int)>> operators =
//     {
//         {"+", [](int a, int b) {return a + b;}},
//         {"-", [](int a, int b) {return a - b;}},
//         {"*", [](int a, int b) {return a * b;}},
//         {"/", [](int a, int b) {return a / b;}}
//     };
//     int evalRPN(vector<string>& tokens) 
//     {
//         if (tokens.size() == 1)
//         {
//             return stoi(tokens[0]);
//         }

//         stack<int> s;

//         for (string & token : tokens)
//         {
//             if (operators.contains(token))
//             {
//                 int b = s.top();
//                 s.pop();
//                 int a = s.top();
//                 s.pop();
//                 s.push(operators[token](a, b));
//             }
//             else
//             {
//                 s.push(stoi(token));
//             }
//         }

//         return s.top();
//     }
// };

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            } else if (c == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            } else if (c == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            } else if (c == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};