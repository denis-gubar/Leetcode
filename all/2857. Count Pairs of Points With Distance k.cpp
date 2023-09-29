class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int K) {
        map<pair<int, int>, int> M;
        int result = 0;
        int N = coordinates.size();
        for (int i = 0; i < N; ++i)
        {
            int const& x = coordinates[i][0];
            int const& y = coordinates[i][1];
            for (int j = 0; j <= K; ++j)
            {
                int tx = x ^ j;
                int ty = y ^ (K - j);
                if (M.find({ tx, ty }) != M.end())
                    result += M[{tx, ty}];
            }
            ++M[{x, y}];
        }
        return result;
    }
};
