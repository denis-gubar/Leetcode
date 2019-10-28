class Solution {
public:
    bool check( const string& s )
    {
        if (s.back() == '.' || s[0] == '.')
            return false;
        if (s.find( '.' ) != string::npos && s.back() == '0')
            return false;
        if (s.size() > 1 && s[0] == '0' && s[1] != '.')
            return false;
        return true;
    }
    vector<string> ambiguousCoordinates( string S ) {
        vector<string> result;
        int N = S.size() - 2;
        for (int i = 1; i < N; ++i)
        {
            string A = S.substr( 1, i );
            string B = S.substr( 1 + i, N - i );
            int a = A.size(), b = B.size();
            vector<string> SA;            
            for (int i = 1; i < a; ++i)
            {
                string t = A;
                t.insert( i, 1, '.' );
                SA.push_back( t );
            }
            SA.push_back( A );
            vector<string> SB;
            for (int i = 1; i < b; ++i)
            {
                string t = B;
                t.insert( i, 1, '.' );
                SB.push_back( t );
            }
            SB.push_back( B );
            a = SA.size(), b = SB.size();
            for (int i = 0; i < a; ++i)
                if (check( SA[i] ))
                    for (int j = 0; j < b; ++j)
                        if (check( SB[j] ))
                            result.push_back( "(" + SA[i] + ", " + SB[j] + ")" );            
        }
        return result;
    }
};