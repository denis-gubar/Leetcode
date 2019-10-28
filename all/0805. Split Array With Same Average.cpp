class Solution {
public:
    bool splitArraySameAverage( vector<int>& A ) {
        int N = A.size();
        int total = accumulate( A.begin(), A.end(), 0 );
        vector<vector<char>> M( total + 1, vector<char>(N + 1) );        
        for (int i = 0; i < N; ++i)
        {
            M[0][i] = 1;
            for (int x = A[i]; x <= total; ++x)
            {
                if (M[x - A[i]][i])
                {
                    M[x - A[i]][i + 1] = M[x - A[i]][i];
                    int n = M[x - A[i]][i];
                    M[x][i + 1] = n + 1;
                    if (n < N && total * n == x * N)
                        return true;
                }                
            }
        }
        return false;
    }
};