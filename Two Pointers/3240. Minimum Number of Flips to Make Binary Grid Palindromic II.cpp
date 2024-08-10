class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        int result = 0;
        for (int x = 0, y = N - 1; x < y; ++x, --y)
            for (int a = 0, b = M - 1; a < b; ++a, --b)
            {
                int count = grid[x][a] + grid[x][b] + grid[y][a] + grid[y][b];
                result += min(count, 4 - count);
            }
        if (N % 2 && M % 2)
        {
            int delta = 0, count = 0;
            for (int x = 0, y = N - 1, j = M / 2; x < y; ++x, --y)
                delta += grid[x][j] != grid[y][j],
                result += grid[x][j] != grid[y][j],
                count += (grid[x][j] + grid[y][j]) / 2;
            for (int a = 0, b = M - 1, i = N / 2; a < b; ++a, --b)
                delta += grid[i][a] != grid[i][b],
                result += grid[i][a] != grid[i][b],
                count += (grid[i][a] + grid[i][b]) / 2;
            if (count % 2 && delta == 0)
                result += 2;
            result += grid[N / 2][M / 2];
        }
        else if (N % 2)
        {
            int delta = 0, count = 0;
            for (int a = 0, b = M - 1, i = N / 2; a < b; ++a, --b)
                delta += grid[i][a] != grid[i][b],
                result += grid[i][a] != grid[i][b],
                count += (grid[i][a] + grid[i][b]) / 2;
            if (count % 2 && delta == 0)
                result += 2;
        }
        else if (M % 2)
        {
            int delta = 0, count = 0;
            for (int x = 0, y = N - 1, j = M / 2; x < y; ++x, --y)
                delta += grid[x][j] != grid[y][j],
                result += grid[x][j] != grid[y][j],
                count += (grid[x][j] + grid[y][j]) / 2;
            if (count % 2 && delta == 0)
                result += 2;
        }
        return result;
    }
};
