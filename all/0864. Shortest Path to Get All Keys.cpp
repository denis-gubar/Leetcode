int static F[30][30][64];
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int result = 0;
        int N = grid.size(), M = grid[0].size();
        array dx = { -1, 0, 1, 0 };
        array dy = { 0, -1, 0, 1 };
        char x = '@';
        char sx = -1, sy = -1, mask = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                x = max(x, grid[i][j]);
                if (grid[i][j] == '@')
                    sx = i, sy = j;
            }
        int K = x - 'a' + 1;
        int endMask = (1 << K) - 1;
        memset(F, -1, sizeof(F));
        F[sx][sy][mask] = 0;
        queue<int> Q;
        Q.push(sx); Q.push(sy); Q.push(mask);
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            int mask = Q.front(); Q.pop();
            if (mask == endMask)
                return F[x][y][mask];
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                    if (grid[nx][ny] != '#' &&
                        ("ABCDEF"s.find(grid[nx][ny]) == string::npos || (mask & (1 << (grid[nx][ny] - 'A'))) != 0) &&
                        grid[nx][ny])
                    {
                        int nmask = mask;
                        if ("abcdef"s.find(grid[nx][ny]) != string::npos)
                            nmask |= 1 << (grid[nx][ny] - 'a');
                        if (F[nx][ny][nmask] < 0)
                        {
                            F[nx][ny][nmask] = F[x][y][mask] + 1;
                            Q.push(nx); Q.push(ny); Q.push(nmask);
                        }
                    }
            }
        }
        return -1;
    }
};
