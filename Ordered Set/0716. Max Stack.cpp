class MaxStack {
public:
	/** initialize your data structure here. */
	MaxStack() {

	}

	void push(int x) {
		sorted[x].push_back(data.size());
		data.push(x);
	}

	int pop() {
		int result = data.top();
		sorted[result].pop_back();
		data.pop();
		clean();
		return result;
	}

	int top() {
		return data.top();
	}

	int peekMax() {
		return sorted.begin()->first;
	}

	int popMax() {
		int result = sorted.begin()->first;
		sorted.begin()->second.pop_back();
		clean();
        return result;
	}
	
	void clean()
	{
        while(sorted.begin()->second.empty())
            sorted.erase(sorted.begin());
		while (!data.empty() && (sorted.find(data.top()) == sorted.end() || sorted[data.top()].back() + 1 != data.size()))
			data.pop();
    }
	map<int, vector<int>, greater<int>> sorted;
	stack<int> data;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */