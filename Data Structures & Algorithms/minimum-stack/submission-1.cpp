#include <stack>

class MinStack {
public:
    stack<int> elems;
    stack<int> current_mins;

    MinStack() : elems(), current_mins() {}
    
    void push(int val) 
    {
        elems.push(val);
        if (current_mins.empty() || current_mins.top() >= val)
        {
            current_mins.push(val);
        }
        else
        {
            current_mins.push(current_mins.top());
        }
    }
    
    void pop() 
    {
        elems.pop();
        current_mins.pop();    
    }
    
    int top() 
    {
        return elems.top();
    }
    
    int getMin() 
    {
        return current_mins.top();    
    }
};
