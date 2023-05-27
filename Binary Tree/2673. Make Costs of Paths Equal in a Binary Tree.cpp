class Solution {
public:
    int minIncrements(int N, vector<int>& cost) {
        int result = 0;
        vector<int> A(cost);
        for (int i = 0; i < N / 2; ++i)
        {
            A[2 * i + 1] += A[i];
            A[2 * i + 2] += A[i];
        }
        int T = *max_element(A.begin(), A.end());
        vector<int> M(A), D(N);
        for (int i = N / 2 - 1; i >= 0; --i)
            M[i] = max(M[2 * i + 1], M[2 * i + 2]);
        for (int i = 0; i < N; ++i)
        {
            result += T - M[i] - D[i];
            D[i] = T - M[i];
            if (i < N / 2)
            {
                D[2 * i + 1] += D[i];
                D[2 * i + 2] += D[i];
            }
        }
        return result;
    }
};
