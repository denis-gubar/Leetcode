class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet(): gen(mt19937(rd())) {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (M.find(val) != M.end())
			return false;
		M[val] = data.size();
		data.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (auto it = M.find(val); it == M.end())
			return false;
		else
		{
			int index = it->second;
            data[index] = data.back();				
            M[data[index]] = index;				
			data.pop_back();
			M.erase(it);
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		uniform_int_distribution<int> distribution(0, data.size() - 1);
		return data[distribution(gen)];
	}
	vector<int>	data;
	unordered_map<int, int> M;
	random_device rd;
	mt19937 gen;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */