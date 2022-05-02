class Solution {
public:
    bool check(vector<int> A)
    {
        int N = A.size();
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i)
            if (A[i] != i + 1)
                return false;
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int N = matrix.size();        
        for (int i = 0; i < N; ++i)
        {
            vector<int> A = matrix[i];
            if (!check(A))
                return false;
            A.clear();
            for (int j = 0; j < N; ++j)
                A.push_back(matrix[j][i]);
            if (!check(A))
                return false;
        }
        return true;
    }
};
