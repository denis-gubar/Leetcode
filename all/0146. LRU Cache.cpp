class LRUCache {
public:
	LRUCache(int capacity): capacity(capacity) {

	}

	int get(int key) {
		if (auto it = data.find(key); it == data.end())
			return -1;
		else
		{
			auto lit = links.find(key);
			Q.erase(lit->second);
			Q.push_front(key);
			lit->second = Q.begin();
			return it->second;
		}
	}

	void put(int key, int value) {
		data[key] = value;
		if (auto it = links.find(key); it != links.end())
		{
			Q.erase(it->second);
			Q.push_front(key);
			it->second = Q.begin();
		}
		else
		{
			Q.push_front(key);
			links[key] = Q.begin();
		}
		if (Q.size() > capacity)
		{
			links.erase(links.find(Q.back()));
			data.erase(data.find(Q.back()));
			Q.pop_back();
		}
	}
	int capacity;
	unordered_map<int, int> data;
	list<int> Q;
	unordered_map<int, list<int>::iterator> links;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */