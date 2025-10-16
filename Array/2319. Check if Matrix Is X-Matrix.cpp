class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        for (int i = 0; i < N; ++i)
            if (grid[i][i] == 0 || grid[i][N - i - 1] == 0)
                return false;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && j != N - i - 1 && grid[i][j] != 0)
                    return false;
        return true;
    }
};
