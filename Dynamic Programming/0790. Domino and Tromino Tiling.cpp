class Solution {
public:
    const int MOD = 1000000007;
    int numTilings( int N ) {
        vector<int> M( N + 1 );
        M[0] = 1;
        for (int i = 1; i <= N; ++i)
        {
            M[i] = M[i - 1];
            if (i > 1)
            {
                M[i] += M[i - 2];
                M[i] %= MOD;
            }
            for (int k = 0; k <= i - 3; ++k)
            {                
                M[i] += 2 * M[k] % MOD;
                M[i] %= MOD;
            }
        }
        return M[N];
    }
};