class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int a = x, b = x + k - 1; a < b; ++a, --b)
            for (int c = y; c < y + k; ++c)
                swap(grid[a][c], grid[b][c]);
        return grid;
    }
};
