class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int INF = 1'000'000;
        vector<vector<int>> F(N, vector<int>(M, INF));
        F[0][0] = 0;
        vector<int> dx{ 0, -1, 0, 1 };
        vector<int> dy{ -1, 0, 1, 0 };
        set<pair<int, pair<int, int>>> S;
        S.insert({ 0, {0, 0} });
        bool isStarted = false;
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
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && F[nx][ny] == INF)
                {
                    if (t + 1 < grid[nx][ny] && !isStarted)
                        continue;
                    int delta = 0;
                    if (t + 1 < grid[nx][ny])
                        delta = (grid[nx][ny] - t) / 2 * 2;
                    F[nx][ny] = t + 1 + delta;
                    S.insert({ F[nx][ny], {nx, ny} });
                    isStarted = true;
                }
            }
        }
        int result = F[N - 1][M - 1];
        if (result == INF)
            result = -1;
        return result;
    }
};
