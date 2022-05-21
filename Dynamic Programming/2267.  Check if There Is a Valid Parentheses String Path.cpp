class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> dx{ 1, 0 };
        vector<int> dy{ 0, 1 };
        int total = N * M;
        vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(total / 2 + 2)));
        queue<int> Q;
        if (grid[0][0] == '(')
        {
            visited[0][0][1] = true;
            Q.push(0), Q.push(0), Q.push(1);
        }
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            int balance = Q.front(); Q.pop();
            for (int z = 0; z < 2; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                {
                    int newBalance = balance + (grid[nx][ny] == '(' ? 1 : -1);
                    if (newBalance >= 0 && newBalance * 2 <= total && !visited[nx][ny][newBalance])
                    {
                        visited[nx][ny][newBalance] = true;
                        Q.push(nx), Q.push(ny), Q.push(newBalance);
                    }
                }
            }
        }
        return visited[N - 1][M - 1][0];
    }
};
