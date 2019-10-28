class StockSpanner {
public:
	StockSpanner() : pos(0) {
		A.clear();
		spans.clear();
	}

	int next(int price) {
		A.push_back(price);
		int result = 1;
		if (pos && A[pos] >= A[pos - 1])
		{
			for (int x = pos - 1; x >= 0 && A[x] <= A[pos]; x -= spans[x])
				result += spans[x];
		}
		++pos;
		spans.push_back(result);
		return result;
	}
	vector<int> A, spans;
	int pos;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */