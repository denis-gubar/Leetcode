class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		S.clear();
	}

	void addNum(int val) {
		auto it = S.lower_bound(val * 2 - 1);
		if (it != S.end())
		{
			if (*it == val * 2 - 1)
			{
				S.erase(it);
				if (S.find(val * 2 + 2) == S.end())
					S.insert(val * 2 + 1);
				else
					S.erase(val * 2 + 2);
				return;
			}
			else if (*it % 2 || *it == val * 2)
				return;
			S.insert(val * 2);
			if (S.find(val * 2 + 2) == S.end())
				S.insert(val * 2 + 1);
			else
				S.erase(val * 2 + 2);
		}
		else
		{
			S.insert(val * 2); S.insert(val * 2 + 1);
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> result;
		for (auto it = S.begin(); it != S.end(); ++it)
		{
			int a = *it / 2; ++it;
			int b = *it / 2;
			result.push_back({ a, b });
		}
		return result;
	}
	set<int> S;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */