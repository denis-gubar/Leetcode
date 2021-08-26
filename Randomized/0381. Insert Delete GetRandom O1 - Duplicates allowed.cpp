class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() : gen(mt19937(rd())) {
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		auto it = M.find(val);
		bool result = it == M.end();
		M[val].insert(data.size());
		data.push_back(val);
		return result;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (auto it = M.find(val); it != M.end())
		{
			int index = *(it->second.begin());
			if (val != data.back())
			{
				data[index] = data.back();
				M[data[index]].erase(data.size() - 1);
				M[data[index]].insert(index);
			}
			it->second.erase(index);
			if (it->second.empty())
				M.erase(it);
			data.pop_back();
			return true;
		}
		return false;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		uniform_int_distribution<int> distribution(0, data.size() - 1);
		return data[distribution(gen)];
	}
	vector<int> data;
	unordered_map<int, unordered_set<int>> M;
	random_device rd;
	mt19937 gen;
};