class FrontMiddleBackQueue {
public:
	FrontMiddleBackQueue() {

	}

	void pushFront(int val) {
		prefix.push_front(val);
		if (suffix.size() + 2 == prefix.size())
		{
			suffix.push_front(prefix.back());
			prefix.pop_back();
		}
	}

	void pushMiddle(int val) {
		if (prefix.size() > suffix.size())
		{
			suffix.push_front(prefix.back());
			prefix.pop_back();
		}
		prefix.push_back(val);
	}

	void pushBack(int val) {
		suffix.push_back(val);
		if (suffix.size() > prefix.size())
		{
			prefix.push_back(suffix.front());
			suffix.pop_front();
		}
	}

	int popFront() {
		if (prefix.empty())
			return -1;
		int result = prefix.front();
		prefix.pop_front();
		if (suffix.size() > prefix.size())
		{
			prefix.push_back(suffix.front());
			suffix.pop_front();
		}
		return result;
	}

	int popMiddle() {
		if (prefix.empty())
			return -1;
		int result = prefix.back();
		prefix.pop_back();
		if (suffix.size() > prefix.size())
		{
			prefix.push_back(suffix.front());
			suffix.pop_front();
		}
		return result;
	}

	int popBack() {
		if (prefix.size() > suffix.size())
		{
			suffix.push_front(prefix.back());
			prefix.pop_back();
		}
		if (suffix.empty())
			return -1;
		int result = suffix.back();
		suffix.pop_back();
		return result;
	}
	deque<int> prefix, suffix;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */