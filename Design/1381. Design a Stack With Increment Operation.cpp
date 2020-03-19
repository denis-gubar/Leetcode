class CustomStack {
public:
	CustomStack(int maxSize): maxSize(maxSize) {
		S.reserve(maxSize);
		delta.reserve(maxSize);
		delta.resize(maxSize, 0);
	}

	void push(int x) {
		if (S.size() < maxSize)
			S.push_back(x);
	}

	int pop() {
		if (S.empty()) return -1;
		int pos = S.size() - 1;
		int result = S[pos];
        S.pop_back();
		result += delta[pos];
		if (pos) delta[pos - 1] += delta[pos];
		delta[pos] = 0;        
		return result;
	}

	void increment(int k, int val) {
		if (S.empty()) return;
		int pos = min(k - 1, static_cast<int>(S.size()) - 1);
		delta[pos] += val;
	}
	int maxSize;
	vector<int> S;
	vector<int> delta;
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */