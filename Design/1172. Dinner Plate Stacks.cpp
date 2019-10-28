class DinnerPlates {
public:
	DinnerPlates(int capacity) : capacity(capacity), data({ {} }), left(0), right(0) {
	}

	void push(int val) {
		while (data[left].size() == capacity)
			if (left + 1 < data.size())
				++left;
			else
				break;			
		if (data[left].size() < capacity)
			data[left].push_back(val);
		else
		{
			++left;
			if (data.size() > left)
				data[left].push_back(val);
			else
				data.push_back({ val });
		}
		right = max(left, right);
	}

	int pop() {
		while (data.size() > 1 && data.back().empty())
		{
			data.pop_back();
			right = min<int>(right, data.size() - 1);
		}
		left = min(left, right);
		if (data.back().empty())
			return -1;
		int result = data.back().back();
		data.back().pop_back();
		return result;
	}

	int popAtStack(int index) {
		if (data.size() > index && !data[index].empty())
		{
			left = min(left, index);
			int result = data[index].back();
			data[index].pop_back();
			return result;
		}
		return -1;
	}
	vector<vector<int>> data;
	int capacity;
	int left;
	int right;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */