class StockSpanner {
public:
    StockSpanner() {
        A.reserve(10'000);
    }
    
    int next(int price) {
        int result = A.size() + 1;
        while (!S.empty() && A[S.top()] <= price)
            S.pop();
        if (!S.empty())
            result = A.size() - S.top();
        S.push(A.size());
        A.push_back(price);
        return result;
    }
    vector<int> A;
    stack<int> S;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
