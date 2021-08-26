class Solution {
private:
    vector<vector<int>>* M;
    int m, n;
    int f( int a )
    {
        return (*M)[a / n][a % n];
    }
public:
    bool searchMatrix( vector<vector<int>>& matrix, int target ) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        M = &matrix;
        m = matrix.size(), n = matrix[0].size();
        int a = 0, b = m * n - 1;
        if (target < f(a) || target > f(b))
            return false;
        while (a + 1 < b)
        {
            int median = (a + b) / 2;
            if (f(median) < target)
                a = median;
            else
                b = median;
        }
        return (target == f(a) || target == f(b));
    }
};
