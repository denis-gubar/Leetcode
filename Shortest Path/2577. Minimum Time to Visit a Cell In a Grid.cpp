static int F[1'000][1'000];
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        memset(F, -1, sizeof(F));
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        set<pair<int, pair<int, int>>> S;
        S.insert({ 0, {0, 0} });
        while (!S.empty())
        {
            pair<int, pair<int, int>> P = *S.begin();
            int const& t = P.first;
            int const& x = P.second.first;
            int const& y = P.second.second;
            S.erase(S.begin());
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && F[nx][ny] == -1)
                {
                    int delta = 0;
                    if (t + 1 < grid[nx][ny])
                        delta = (grid[nx][ny] - t) / 2 * 2;
                    if (F[nx][ny] == -1 || F[nx][ny] > t + 1 + delta)
                    {
                        F[nx][ny] = t + 1 + delta;
                        S.insert({ F[nx][ny], {nx, ny} });
                    }
                }
            }
        }
        return F[N - 1][M - 1];
    }
};
