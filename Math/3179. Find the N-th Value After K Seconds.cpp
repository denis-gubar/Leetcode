static int const MOD = 1'000'000'007;
class Solution {
public:
    int valueAfterKSeconds(int N, int K) {
        vector<int> A(N, 1);
        for (int i = 0; i < K; ++i)
        {
            int sum = 0;
            for (int j = 0; j < N; ++j)
            {
                sum += A[j];
                sum %= MOD;
                A[j] = sum;
            }
        }
        return A[N - 1];
    }
};
