class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int left = N, right = 0, bottom = 0, top = M;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j])
                    left = min(left, j),
                    right = max(right, j),
                    top = min(top, i),
                    bottom = max(bottom, i);
        return (right - left + 1) * (bottom - top + 1);
    }
};
