class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (minimums.empty())
            minimums.push(x);
        else
            minimums.push(min(x, minimums.top()));
    }
    
    void pop() {
        data.pop();
        minimums.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minimums.top();
    }
    stack<int> data;
    stack<int> minimums;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */