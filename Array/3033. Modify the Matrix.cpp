class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> result = matrix;
        int N = matrix.size(), M = matrix[0].size();
        vector<int> C(M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[j] = max(C[j], matrix[i][j]);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (result[i][j] == -1)
                    result[i][j] = C[j];
        return result;
    }
};
