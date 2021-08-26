class Solution {
public:
    static const int MOD = 1000000007;
    int uniqueLetterString( string S ) {
        if (S.empty())
            return 0;
        long long result = 0;        
        int N = S.size();        
        for (long long a = 0; a < N; ++a)
        {
            long long b = a;
            long long uniqueCount = 0;
            vector<int> letterCount( 256 );
            while (b < N)
            {
                int x = ++letterCount[S[b]];
                if (x == 1)
                    ++uniqueCount;
                else if (x == 2)
                    --uniqueCount;
                result += uniqueCount;                
                ++b;
            }
            result %= MOD;
        }
        return result;
    }
};