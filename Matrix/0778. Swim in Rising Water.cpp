class Solution {
public:
    vector<vector<int>> g;
    vector<int> dx, dy;
    int N;
    bool calc( int t )
    {
        queue<int> Q;
        vector<char> isVisited( N * N );
        int x = 0, y = 0;
        if (g[x][y] <= t)
        {
            isVisited[g[x][y]] = 1;
            Q.push( x ); Q.push( y );
        }
        while (!Q.empty())
        {
            x = Q.front(); Q.pop();
            y = Q.front(); Q.pop();
            if (x == N - 1 && y == N - 1)
                return true;
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[g[nx][ny]] && g[nx][ny] <= t)
                {
                    isVisited[g[nx][ny]] = 1;
                    Q.push( nx ); Q.push( ny );
                }
            }
        }
        return false;
    }
    int swimInWater( vector<vector<int>>& grid ) {
        g = grid;
        dx = { 0, 1, 0, -1 };
        dy = { 1, 0, -1, 0 };
        N = g.size();
        int a = max(g[0][0], g[N - 1][N - 1]) - 1, b = N * N - 1;
        while (a + 1 < b)
        {            
            int median = (a + b) / 2;
            if (calc( median ))
                b = median;
            else
                a = median;
        }
        return b;
    }
};