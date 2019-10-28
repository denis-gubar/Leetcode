class FreqStack {
public:
	FreqStack() {
		priorityQueue.clear();
		positions.clear();
		order = 0;
	}

	void push(int x) {
		++order;
		vector<int>& pos = positions[x];
		pos.push_back(order);
		priorityQueue.insert({ -pos.size(), {-order, x} });
	}

	int pop() {
		auto it = priorityQueue.begin();
		auto top = *it;
		priorityQueue.erase(it);
		int result = top.second.second;
		vector<int>& pos = positions[result];
		pos.pop_back();
		if (top.first != -1)
			priorityQueue.insert({ -pos.size(), {-pos.back(), result} });		
		return result;
	}
private:
	int order;
	set<pair<int, pair<int, int>>> priorityQueue;
	map<int, vector<int>> positions;
};