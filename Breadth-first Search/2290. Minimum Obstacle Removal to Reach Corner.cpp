class Solution {
public:    
    int minimumObstacles(vector<vector<int>>& grid) {
        constexpr int INF = 1 << 20;
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N, vector<int>(M, INF));
        vector<int> dx{ 0, -1, 0, 1 };
        vector<int> dy{ -1, 0, 1, 0 };
        auto encode = [M](int x, int y)
        {
            return x * M + y;
        };
        auto decode = [M](int a)
        {
            return pair<int, int>(a / M, a % M);
        };        
        F[0][0] = 0;
        set<pair<int, int>> S;
        S.insert({ 0, encode(0, 0) });
        while (!S.empty())
        {
            auto p = *S.begin();
            S.erase(S.begin());
            int const& weight = p.first;
            int const& a = p.second;
            auto [x, y] = decode(a);
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && F[nx][ny] == INF)
                {
                    F[nx][ny] = weight + grid[nx][ny];
                    S.insert({ F[nx][ny], encode(nx, ny) });
                }
            }
        }
        return F[N - 1][M - 1];
    }
};
