static short F[102][102];
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        memset(F, 100, sizeof(F));
        int const INF = F[0][0];
        int const N = maze.size(), M = maze[0].size();
        int result = INF;
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, 1, 0, -1 };
        if (result == INF)
            result = -1;
        queue<int> Q;
        Q.push(entrance[0] + 1), Q.push(entrance[1] + 1);
        F[entrance[0] + 1][entrance[1] + 1] = 0;
        while (!Q.empty())
        {
            int const x = Q.front(); Q.pop();
            int const y = Q.front(); Q.pop();
            int const t = F[x][y];
            if (x == 0 || x == N + 1 || y == 0 || y == M + 1)
            {
                if (t == 1)
                    continue;
                result = t - 1;
                break;
            }
            for (int z = 0; z < 4; ++z)
            {
                int const nx = x + dx[z];
                int const ny = y + dy[z];
                if (nx == 0 || nx == N + 1 || ny == 0 || ny == M + 1 || F[nx][ny] == INF && maze[nx - 1][ny - 1] == '.')
                    Q.push(nx), Q.push(ny), F[nx][ny] = F[x][y] + 1;
            }
        }
        return result;
    }
};
