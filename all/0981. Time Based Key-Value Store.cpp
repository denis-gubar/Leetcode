class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {
		M.clear();
	}

	void set(string key, string value, int timestamp) {
		M[key].push_back({ timestamp, value });
	}

	string get(string key, int timestamp) {
		if (M.find(key) == M.end())
			return "";
		auto it = lower_bound(M[key].begin(), M[key].end(), pair<int, string>{ timestamp, "~" });
        if (it == M[key].begin())
            return "";
		return (--it)->second;
	}
	map<string, vector<pair<int, string>>> M;
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */