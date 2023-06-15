class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> result(N, vector<int>(M));
        unordered_map<int, pair<int, int>> F;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (F.find(i - j) == F.end())
                    F[i - j] = { i, j };
        for (auto [key, value] : F)
        {
            int i = value.first;
            int j = value.second;
            unordered_map<int, int> L, R;
            int a = 0, b = 0;
            for (int x = i + 1, y = j + 1; x < N && y < M; ++x, ++y)
                if (++R[grid[x][y]] == 1)
                    ++b;
            for (int x = i, y = j; x < N && y < M; ++x, ++y)
            {
                if (x > 0 && y > 0)
                {
                    if (++L[grid[x - 1][y - 1]] == 1)
                        ++a;
                    if (--R[grid[x][y]] == 0)
                        --b;
                }
                result[x][y] = abs(a - b);
            }
        }
        return result;
    }
};
