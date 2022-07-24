class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(), M = matrix[0].size();
        int i = N - 1, j = 0;
        while (i >= 0 && j < M)
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --i;
            else
                ++j;
        return false;
    }
};
