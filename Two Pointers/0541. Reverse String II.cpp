class Solution {
public:
    string reverseStr( string s, int k ) {
        string result( s );
        int i = 0;
        for (; i + k <= s.size(); i += 2 * k)
            reverse( result.begin() + i, result.begin() + i + k );
        if ( i < s.size() )
            reverse( result.begin() + i, result.end() );
        return result;
    }
};