class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int N = rooks.size();
        int result = 0;
        for (int x = 0; x < 2; ++x)
        {
            sort(rooks.begin(), rooks.end(), [x](vector<int> const& a, vector<int> const& b)
                {
                    return a[x] < b[x];
                });
            for (int i = 0; i < N; ++i)
                result += abs(i - rooks[i][x]);
        }
        return result;
    }
};
