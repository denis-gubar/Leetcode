class Solution {
public:
    vector<string> letterCasePermutation( string S ) {
        vector<string> result;
        int N = S.size();
        for (int x = 0; x < (1 << N); ++x)
        {
            string s{ S };
            for (int k = 0; k < N; ++k)
            {
                if (x & (1 << k))
                    s[k] = ::tolower( s[k] );
                else
                    s[k] = ::toupper( s[k] );
            }
            result.push_back( s );
        }
        sort( result.begin(), result.end() );
        result.erase( unique( result.begin(), result.end() ), result.end() );
        return result;
    }
};