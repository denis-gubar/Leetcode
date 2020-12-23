class OrderedStream {
public:
	OrderedStream(int n): n(n), last(-1), data(vector<string>(n)) {
	}

	vector<string> insert(int id, string value) {
		data[id - 1] = value;
		vector<string> result;
		for (int i = last + 1; i < n; ++i)
			if (data[i].empty())
				break;
			else
			{
				last = i;
				result.push_back(data[i]);
			}
		return result;
	}
	int n;
	int last;
	vector<string> data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */