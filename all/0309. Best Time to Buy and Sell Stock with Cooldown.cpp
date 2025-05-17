class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int empty = 0, have = -(1 << 30), sold = -(1 << 30);
        for (int price : prices)
        {
            int nEmpty = max(empty, sold);
            int nHave = max(have, empty - price);
            int nSold = have + price;
            empty = nEmpty, have = nHave, sold = nSold;
        }
        return max(empty, sold);
    }
};
