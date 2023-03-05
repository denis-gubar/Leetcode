class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        if (N * M <= 2)
            return false;
        if (N == 1 || M == 1)
            return true;
        vector<int> dx{ -1, 0, 1, 0 };
        vector<int> dy{ 0, -1, 0, 1 };
        vector<vector<int>> F(N, vector<int>(M));
        F[0][0] = 1;
        if (grid[0][1] == 1)
            F[0][1] = 2;
        if (grid[1][0] == 1)
            F[1][0] = 3;
        for (int j = 2; j < M; ++j)
        {
            if (grid[0][j] == 0)
                break;
            F[0][j] = 2;
        }
        for (int i = 2; i < N; ++i)
        {
            if (grid[i][0] == 0)
                break;
            F[i][0] = 3;
        }
        int x = 4;
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < M; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                if (grid[i - 1][j] == 0)
                {
                    F[i][j] = F[i][j - 1];
                    continue;
                }
                if (grid[i][j - 1] == 0)
                {
                    F[i][j] = F[i - 1][j];
                    continue;
                }
                if (F[i - 1][j] == F[i][j - 1])
                    F[i][j] = F[i][j - 1];
                else
                {
                    F[i][j] = x;
                    ++x;
                }
            }
        if (F[N - 1][M - 1] == F[N - 2][M - 1] || F[N - 1][M - 1] == F[N - 1][M - 2])
            return true;
        return false;
    }
};
