class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> dx = { -1, -1, -1, 0, 1, 1, 1 };
        vector<int> dy = { -1, 0, 1, 0, -1, 0, 1 };
        int result = 0;
        for(int i = 1; i + 1 < N; ++i)
            for (int j = 1; j + 1 < M; ++j)
            {
                int current = 0;
                for (int z = 0; z < 7; ++z)
                    current += grid[i + dx[z]][j + dy[z]];
                result = max(result, current);
            }
        return result;
    }
};
