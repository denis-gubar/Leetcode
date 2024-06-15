class Solution {
public:
    vector<int> kthSmallestPrimeFraction( vector<int>& A, int K ) {
        int N = A.size();
        vector<vector<int>> M;
        M.reserve(N * N);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                M.push_back( { A[i], A[j] } );
        --K;
        nth_element( M.begin(), M.begin() + K, M.end(), []( const vector<int>& a, const vector<int>& b )
                     {
                         return a[0] * b[1] < b[0] * a[1];
                     } );
        return M[K];
    }
};