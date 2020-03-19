class Solution {
public:
    int largestOverlap( vector<vector<int>>& A, vector<vector<int>>& B ) {
        int result = 0;
        int N = A.size();        
        for (int dx = -N + 1; dx <= N - 1; ++dx)
            for (int dy = -N + 1; dy <= N - 1; ++dy)
            {
                int current = 0;
                for (int i = 0; i < N; ++i)
                    if (dx + i >= 0 && dx + i < N)
                        for (int j = 0; j < N; ++j)
                            if (dy + j >= 0 && dy + j < N && B[i][j])
                                current += A[dx + i][dy + j];
                result = max( result, current );
            }
        return result;
    }
};