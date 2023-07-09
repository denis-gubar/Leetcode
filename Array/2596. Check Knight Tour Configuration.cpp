class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> dx = { -2, -2, -1, -1, 1, 1, 2, 2 };
        vector<int> dy = { -1, 1, -2, 2, -2, 2, -1, 1 };
        int x = 0, y = 0;
        for (int i = 1; i < N * N; ++i)
        {
            for (int z = 0; z < 8; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == i)
                {
                    x = nx;
                    y = ny;
                    break;
                }
            }
            if (grid[x][y] != i)
                return false;
        }
        return true;
    }
};
