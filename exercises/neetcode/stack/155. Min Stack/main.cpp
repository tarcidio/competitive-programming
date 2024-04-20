class MinStack {
private:
    stack<int> value;
    stack<int> minValue;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        value.push(val);
        int newMinValue = min(val, minValue.empty() ? val : minValue.top());
        minValue.push(newMinValue);
    }
    
    void pop() {
        value.pop();
        minValue.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return minValue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
