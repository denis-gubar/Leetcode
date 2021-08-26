class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): N(k + 1), head(0), tail(0), data(vector<int>(k + 1)) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (head == (tail + 1) % N)
            return false;
        data[tail] = value;
        tail = (tail + 1) % N;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (head == tail)
            return false;
        head = (head + 1) % N;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (head == tail)
            return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (head == tail)
            return -1;
        return data[(tail + N - 1) % N];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == (tail + 1) % N;
    }
    int N;
    int head;
    int tail;
    vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */