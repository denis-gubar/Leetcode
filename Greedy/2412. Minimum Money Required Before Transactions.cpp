class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long result = 0, money = 0;        
        int N = transactions.size();
        sort(transactions.begin(), transactions.end(), [](vector<int>& a, vector<int>& b)
            {
                if (a[1] != b[1])
                    return a[1] < b[1];
                return a[0] < b[0];
            });
        for (int i = 0; i < N; ++i)
            if (transactions[i][0] >= transactions[i][1])
            {
                money -= transactions[i][0];
                result = min(result, money);
                money += transactions[i][1];
            }
        sort(transactions.begin(), transactions.end(), [](vector<int>& a, vector<int>& b)
            {
                if (a[0] != b[0])
                    return a[0] > b[0];
                return a[1] < b[1];
            });
        for (int i = 0; i < N; ++i)
            if (transactions[i][0] < transactions[i][1])
            {
                money -= transactions[i][0];
                result = min(result, money);
                money += transactions[i][1];
            }
        return -result;
    }
};
