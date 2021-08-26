class Solution {
public:
    void rotate( vector<vector<int>>& matrix ) {
        int n = matrix.size();        
        for(int i = 0; i < n / 2 + n % 2; ++i)
            for (int j = 0; j < n / 2; ++j)
            {
                int x1 = i, y1 = j;
                int x2 = j, y2 = n - i - 1;
                int x3 = n - i - 1, y3 = n - j - 1;
                int x4 = n - j - 1, y4 = i;
                int a = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = matrix[x1][y1];
                matrix[x1][y1] = a;
            }
    }
};