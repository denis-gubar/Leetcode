class FirstUnique {
public:
	FirstUnique(vector<int>& nums) {
		for (int n : nums)
			add(n);
        Index.reserve(50000 + nums.size());
	}

	int showFirstUnique() {
		if (Uniques.empty())
			return -1;
		return Uniques.front();
	}

	void add(int value) {
		if (auto it = Index.find(value); it == Index.end())
		{
			Uniques.push_back(value);
			Index[value] = prev(Uniques.end());
		}
		else
		{
			if (it->second != Uniques.end())
			{
				Uniques.erase(it->second);
				it->second = Uniques.end();
			}
		}
	}
	list<int> Uniques;
	unordered_map<int, list<int>::iterator> Index;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */