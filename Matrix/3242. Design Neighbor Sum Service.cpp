class neighborSum {
public:
    int N;
    vector<pair<int, int>> P;
    vector<vector<int>> G;
    neighborSum(vector<vector<int>>& grid) : N(grid.size()), P(vector<pair<int, int>>(N * N)), G(grid) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                P[grid[i][j]] = { i, j };
    }
    
    int get(int x, int y)
    {
        if (x >= 0 && x < N && y >= 0 && y < N)
            return G[x][y];
        return 0;
    }

    int adjacentSum(int value) {
        int const x = P[value].first;
        int const y = P[value].second;
        return get(x - 1, y) + get(x + 1, y) + get(x, y - 1) + get(x, y + 1);
    }
    
    int diagonalSum(int value) {
        int const x = P[value].first;
        int const y = P[value].second;
        return get(x - 1, y - 1) + get(x + 1, y - 1) + get(x - 1, y + 1) + get(x +1, y + 1);
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
