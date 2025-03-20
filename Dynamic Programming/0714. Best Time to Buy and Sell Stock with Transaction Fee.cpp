class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int empty = 0, have = -(1 << 30);
        for (int price : prices)
        {
            int nEmpty = max(empty, price + have - fee);
            int nHave = max(have, empty - price);
            empty = nEmpty, have = nHave;
        }
        return empty;
    }
};
