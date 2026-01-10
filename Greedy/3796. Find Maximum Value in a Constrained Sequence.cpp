static int A[100'000];
class Solution {
public:
    int findMaxVal(int N, vector<vector<int>>& restrictions, vector<int>& diff) {
        int result = 0;
        memset(A, 100, sizeof(A));
        A[0] = 0;
        for (vector<int> const& r : restrictions)
        {
            int const& IDX = r[0];
            int const& MAXVAL = r[1];
            A[IDX] = MAXVAL;
        }
        for (int i = 1; i < N; ++i)
            A[i] = min(A[i], A[i - 1] + diff[i - 1]);
        for (int i = N - 2; i >= 0; --i)
            A[i] = min(A[i], A[i + 1] + diff[i]);
        return *max_element(&A[0], &A[0] + N);
    }
};
