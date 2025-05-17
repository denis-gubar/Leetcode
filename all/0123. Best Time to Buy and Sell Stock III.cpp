class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int const INF = -(1 << 30);
        int empty = 0, empty2 = 0, empty3 = INF, have = INF, have2 = INF;
        for (int price : prices)
        {
            int nEmpty2 = max(empty2, have + price);
            int nEmpty3 = max(empty3, have2 + price);
            int nHave = max(have, empty - price);
            int nHave2 = max(have2, empty2 - price);
            empty2 = nEmpty2, empty3 = nEmpty3, have = nHave, have2 = nHave2;
        }
        return max({ empty, empty2, empty3 });
    }
};
