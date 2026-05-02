class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int const N = matrix.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                result[i] += matrix[i][j];
        return result;
    }
};