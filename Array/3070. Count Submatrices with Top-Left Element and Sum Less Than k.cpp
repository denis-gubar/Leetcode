class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int result = 0;
        int N = grid.size(), M = grid[0].size();
        vector<int> A(M + 1);
        for (int i = 0; i < N; ++i)
        {
            int x = 0;
            for (int j = 0; j < M; ++j)
            {
                x += grid[i][j];
                A[j] += x;
                if (A[j] <= k)
                    ++result;
                else
                    break;
            }
        }
        return result;
    }
};
