class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		Q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int result = Q.front(); Q.pop();
		for (int i = 0; i < Q.size(); ++i)
		{
			Q.push(result);
			result = Q.front(); Q.pop();
		}
		return result;
	}

	/** Get the top element. */
	int top() {
		int result = pop();
		Q.push(result);
		return result;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return Q.empty();
	}
	queue<int> Q;
};