class Solution {
public:
    static const int MOD = 1000000007;
    int numFactoredBinaryTrees( vector<int>& A ) {
        int result = 0;
        sort( A.begin(), A.end() );
        A.erase( unique( A.begin(), A.end() ), A.end() );
        set<int> S( A.begin(), A.end() );
        map<int, int> M;
        for (int i = 0; i < A.size(); ++i)
        {
            M[A[i]] = 1;
            for(int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0 && M.find( A[i] / A[j] ) != M.end())
                {
                    M[A[i]] += 1LL * M[A[j]] % MOD * M[A[i] / A[j]] % MOD;
                    M[A[i]] %= MOD;
                }
        }
        for (const auto& m : M)
        {
            result += m.second;
            result %= MOD;
        }
        return result;
    }
};