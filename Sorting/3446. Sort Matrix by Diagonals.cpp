class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int const N = grid.size();
        vector<vector<int>> result(N, vector<int>(N));
        vector<int> A;
        A.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            A.clear();
            for (int j = 0; j < N - i; ++j)
                A.push_back(grid[i + j][j]);
            sort(A.begin(), A.end(), greater{});
            for (int j = 0; j < N - i; ++j)
                result[i + j][j] = A[j];
        }
        for (int i = 1; i < N; ++i)
        {
            A.clear();
            for (int j = i; j < N; ++j)
                A.push_back(grid[j - i][j]);
            sort(A.begin(), A.end());
            for (int j = i; j < N; ++j)
                result[j - i][j] = A[j - i];
        }
        return result;
    }
};
