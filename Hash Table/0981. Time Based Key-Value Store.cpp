class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {
		M.clear();
	}

	void set(string const& key, string const& value, int timestamp) {
		M[key].push_back({ timestamp, value });
	}

	string get(string const& key, int timestamp) {
		if (M.find(key) == M.end())
			return "";
		auto it = lower_bound(M[key].begin(), M[key].end(), pair<int, string>{ timestamp, "~" });
        if (it == M[key].begin())
            return "";
		return (--it)->second;
	}
	unordered_map<string, vector<pair<int, string>>> M;
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */