class StockPrice {
public:
	StockPrice() {

	}

	void update(int timestamp, int price) {
		auto it = M.find(timestamp);
		if (it == M.end())
		{
			S.insert(price);
			M[timestamp] = price;
		}
		else
		{
			S.erase(S.find(it->second));
			S.insert(price);
			it->second = price;
		}
	}

	int current() {
		return prev(M.end())->second;
	}

	int maximum() {
		return *prev(S.end());
	}

	int minimum() {
		return *S.begin();
	}
	map<int, int> M;
	multiset<int> S;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */