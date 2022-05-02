class Solution {
public:
    struct State
    {
        int distance;
        int price;
        int row;
        int column;
    };
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> result;
        vector<State> S;
        int N = grid.size(), M = grid[0].size();
        int sx = start[0], sy = start[1];
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
        queue<int> Q;
        Q.push(sx); Q.push(sy); Q.push(0);
        vector<vector<bool>> G(N, vector<bool>(M));
		int const& lo = pricing[0];
		int const& hi = pricing[1];
        G[sx][sy] = true;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            int d = Q.front(); Q.pop();
            if (grid[x][y] >= lo && grid[x][y] <= hi)
                S.push_back({ d, grid[x][y], x, y });
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] > 0 && !G[nx][ny])
                {
                    G[nx][ny] = true;
                    Q.push(nx); Q.push(ny); Q.push(d + 1);
                }
            }
        }
        sort(S.begin(), S.end(), [](State a, State b)
            {
                if (a.distance != b.distance)
                    return a.distance < b.distance;
                if (a.price != b.price)
                    return a.price < b.price;
                if (a.row != b.row)
                    return a.row < b.row;
                return a.column < b.column;
            });
        for (int i = 0; i < k && i < S.size(); ++i)
            result.push_back({ S[i].row, S[i].column });
        return result;
    }
};
