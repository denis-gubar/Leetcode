class Solution {
public:
    void setZeroes( vector<vector<int>>& matrix ) {
        if (matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        bool col_flag = false;
        for (int i = 0; i < m; ++i)
            col_flag |= matrix[i][0] == 0;
        bool row_flag = false;
        for (int j = 0; j < n; ++j)
            row_flag |= matrix[0][j] == 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        for (int x = 1; x < m; ++x)
            if (matrix[x][0] == 0)
                for (int y = 1; y < n; ++y)
                    matrix[x][y] = 0;
        for (int y = 1; y < n; ++y)
            if (matrix[0][y] == 0)
                for (int x = 1; x < m; ++x)
                    matrix[x][y] = 0;
        if (col_flag)
            for (int x = 0; x < m; ++x)
                matrix[x][0] = 0;
        if (row_flag)
            for (int y = 0; y < n; ++y)
                matrix[0][y] = 0;
    }
};