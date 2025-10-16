static int F[1'001][1'0001];
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        long long result = 0;
        int const MOD = 1'000'000'007;
        int N = s.size();
        vector<bool> primes(10);
        primes[2] = primes[3] = primes[5] = primes[7] = true;
        if (!primes[s[0] - '0']) return 0;
        s.push_back('2');
        vector<int> A;
        A.push_back(-1);
        for (int i = 0; i < N; ++i)
            if (!primes[s[i] - '0'] && primes[s[i + 1] - '0'])
                A.push_back(i);
        if (A.back() + 1 != N)
            return 0;
        int M = A.size();
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < k; ++j)
                if (F[i][j] > 0)
                {
                    for (int z = i + 1; z < M; ++z)
                        if (A[z] - A[i] >= minLength && j + (N - A[z]) / minLength >= k - 1)
                            F[z][j + 1] = (F[z][j + 1] + F[i][j]) % MOD;
                }        
        return F[M - 1][k];
    }
};
