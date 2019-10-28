class Solution {
public:
    bool isToeplitzMatrix( vector<vector<int>>& matrix ) {
        int n = matrix.size(), m = matrix[0].size();
        for (int k = 0; k < m; ++k)
        {
            for (int i = 0; i + k < m && i < n; ++i)
                if (matrix[i][k + i] != matrix[0][k])
                    return false;
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i + k < n && i < m; ++i)
                if (matrix[k + i][i] != matrix[k][0])
                    return false;
        }
        return true;
    }
};