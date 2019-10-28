class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int result = 0, last = prices[0];
        for(int p: prices)
        {
            if (p > last)
                result += p - last;
            last = p;
        }
        return result;
    }
};