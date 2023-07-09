class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> result(N);
        long long maskA = 0, maskB = 0;
        for (int i = 0; i < N; ++i)
        {
            maskA |= 1LL << A[i];
            maskB |= 1LL << B[i];
            long long x = maskA & maskB;
            for (int k = 1; k <= N; ++k)
                if (x & (1LL << k))
                    ++result[i];
        }
        return result;
    }
};
