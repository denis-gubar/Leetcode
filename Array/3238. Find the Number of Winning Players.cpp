class Solution {
public:
    int winningPlayerCount(int N, vector<vector<int>>& pick) {
        int result = 0;
        int const P = pick.size();
        vector<vector<int>> M(N, vector<int>(11));
        for (int i = 0; i < P; ++i)
        {
            int const& x = pick[i][0];
            int const& y = pick[i][1];
            ++M[x][y];
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < 11; ++j)
                if (M[i][j] > i)
                {
                    ++result;
                    break;
                }
        }
        return result;
    }
};
