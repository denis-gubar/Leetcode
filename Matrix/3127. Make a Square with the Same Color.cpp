class Solution {
public:
    bool check(vector<vector<char>> const& grid)
    {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (grid[i][j] == grid[i][j + 1] &&
                    grid[i][j] == grid[i + 1][j] &&
                    grid[i][j] == grid[i + 1][j + 1])
                    return true;
        return false;
    }
    bool canMakeSquare(vector<vector<char>>& grid) {
        bool result = check(grid);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                int c = grid[i][j];
                grid[i][j] = 'B' + 'W' - c;
                result |= check(grid);
                grid[i][j] = c;
            }
        return result;
    }
};
