class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int N = rooms.size(), M = N ? rooms[0].size() : 0;
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{1, 0, -1, 0};
        queue<int> Q;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if (rooms[i][j] == 0)
                    Q.push(i), Q.push(j);
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            for(int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && rooms[x][y] + 1 < rooms[nx][ny])
                {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    Q.push(nx); Q.push(ny);
                }
            }
        }
    }
};