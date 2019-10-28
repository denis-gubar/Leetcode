class Solution {
public:
    string S;
    string T;
    int n;
    int m;
    vector<vector<int>> M;
    int calc( int ns, int nt )
    {
        if (nt == m)
            return 1;
        if (ns == n)
            return 0;
        if (M[ns][nt] >= 0)
            return M[ns][nt];
        int result = 0;
        string::iterator it = S.begin() + ns;
        while (true)
        {
            it = find( it, S.end(), T[nt] );
            if (it == S.end())
                break;
            else
            {
                result += calc( distance( S.begin(), it ) + 1, nt + 1 );
                ++it;
            }
        }
        return M[ns][nt] = result;
    }
    int numDistinct( string s, string t ) {
        S = s; T = t;
        n = s.size(); m = t.size();
        M = vector<vector<int>>( n + 1, vector<int>( m + 1, -1 ) );
        return calc( 0, 0 );
    }
};