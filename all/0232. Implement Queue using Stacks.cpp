class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        data = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!data.empty())
        {
            temp.push(data.top());
            data.pop();
        }
        int result = temp.top();
        temp.pop();
        while(!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> temp(data);
        int result = -1;
        while(!temp.empty())
        {
            result = temp.top();
            temp.pop();
        }
        return result;        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
    stack<int> data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */