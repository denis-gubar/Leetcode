class StockSpanner {
public:
	StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);
	}

	int next(int price) {
		int result = 1;
		while (!A.empty() && price >= A.top())
		{
			result += spans.top();
            spans.pop();
            A.pop();
		}
        A.push(price);
		spans.push(result);
		return result;
	}
	stack<int> A, spans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */