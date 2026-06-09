class MinStack {
private:
    stack<long> stack;
    long min;
public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty()) {
            min = val;
            stack.push(0);
        }
        else {
            stack.push(val - min);
            if (val < min) min = val; 
        }
        
    }
    
    void pop() {
        if (stack.empty()) return;
        long top_val = stack.top();

        if (top_val < 0) {
            min = min - top_val;
        }
        stack.pop();
    }
    
    int top() {
        long top = stack.top();
        return (top > 0) ? (top + min) : min;
    }
    
    int getMin() {
        return (int)min;
    }
};
