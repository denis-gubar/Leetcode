class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        int result = 0;
        vector<vector<int>> A(N, vector<int>(M));
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                if (matrix[i][j])
                    A[i][j] = (i > 0 ? A[i - 1][j] : 0) + matrix[i][j];        
        for (int i = 0; i < N; ++i)
        {
            sort(A[i].begin(), A[i].end(), greater<int>{});
            for (int j = 0; j < M; ++j)
                result = max(result, A[i][j] * (j + 1));
        }
        return result;
    }
};
