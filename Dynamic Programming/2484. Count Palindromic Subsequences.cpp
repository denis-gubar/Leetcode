static int F[10'002][10][10];
static int R[10'002][10][10];
class Solution {
public:
    int countPalindromes(string s) {
        int const MOD = 1'000'000'007;
        int N = s.size();
        string t(s);
        reverse(t.begin(), t.end());
        long long result = 0;
        memset(F, 0, sizeof(F));
        memset(R, 0, sizeof(R));
        vector<vector<int>> A(10, vector<int>(N + 1));
        vector<vector<int>> B(10, vector<int>(N + 1));
        for (int i = 0; i < N; ++i)
        {
            int x = s[i] - '0';
            for (int d = 0; d < 10; ++d)
                A[d][i + 1] = A[d][i] + (x == d);
            x = t[i] - '0';
            for (int d = 0; d < 10; ++d)
                B[d][i + 1] = B[d][i] + (x == d);
        }
        for (int i = 0; i < N; ++i)
        {
            int x = s[i] - '0';
            for (int d1 = 0; d1 < 10; ++d1)
                for (int d2 = 0; d2 < 10; ++d2)
                {
                    F[i + 1][d1][d2] += F[i][d1][d2];
                    F[i + 1][d1][d2] %= MOD;
                    if (d2 == x)
                    {
                        F[i + 1][d1][d2] += A[d1][i];
                        F[i + 1][d1][d2] %= MOD;
                    }
                }
        }
        for (int i = 0; i < N; ++i)
        {
            int x = t[i] - '0';
            for (int d1 = 0; d1 < 10; ++d1)
                for (int d2 = 0; d2 < 10; ++d2)
                {
                    R[i + 1][d1][d2] += R[i][d1][d2];
                    R[i + 1][d1][d2] %= MOD;
                    if (d2 == x)
                    {
                        R[i + 1][d1][d2] += B[d1][i];
                        R[i + 1][d1][d2] %= MOD;
                    }
                }
        }
        for (int i = 1; i < N - 1; ++i)
        {
            for (int d1 = 0; d1 < 10; ++d1)
                for (int d2 = 0; d2 < 10; ++d2)
                {
                    result += 1LL * F[i][d1][d2] * R[N - i - 1][d1][d2];
                }
            result %= MOD;
        }
        return result;
    }
};
