class Solution {
public:
    bool areSentencesSimilar( vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs ) {
        if ( words1.size() != words2.size() )
            return false;
        set<string> dictionary;
        for ( auto s : words1 )
            dictionary.insert( s );
        for ( auto s : words2 )
            dictionary.insert( s );
        map<string, int> M;
        int k = 0;
        for ( auto s : dictionary )
            M[s] = k++;
        vector<string> P( k, string(k, '0') );
        for ( int i = 0; i < k; ++i )
            P[i][i] = '1';
        for ( auto& p : pairs )
            if ( M.find( p[0] ) != M.end() && M.find(p[1]) != M.end() )
            {
                P[M[p[0]]][M[p[1]]] = '1';
                P[M[p[1]]][M[p[0]]] = '1';
            }
        for ( int i = 0; i < words1.size(); ++i )
            if ( P[M[words1[i]]][M[words2[i]]] == '0' )
                return false;
        return true;
    }
};