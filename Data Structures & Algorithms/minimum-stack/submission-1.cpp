class MinStack {
private:
stack<int> s;
stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
