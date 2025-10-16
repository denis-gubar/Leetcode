int static F[100'001];
class Solution {
public:
    int maximizeTheProfit(int N, vector<vector<int>>& offers) {
        memset(F, 0, sizeof(F));
        sort(offers.begin(), offers.end(), [](vector<int> const& a, vector<int> const& b)
            {
                return a[0] < b[0];
            });
        int O = offers.size();
        int result = 0;
        int pos = 0;
        for (int i = 0; i < O; ++i)
        {
            int const& start = offers[i][0];
            int const& end = offers[i][1];
            int const& gold = offers[i][2];
            while (pos < start)
            {
                F[pos + 1] = max(F[pos + 1], F[pos]);
                ++pos;
            }
            F[end + 1] = max(F[end + 1], F[pos] + gold);
            result = max(result, F[end + 1]);
        }
        return result;
    }
};
