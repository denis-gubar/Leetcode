class Solution {
public:
    string customSortString( string S, string T ) {
        string result;
        result.reserve( T.size() );
        vector<int> counts( 26 );
        for (char c : T)
            ++counts[c - 'a'];
        for (char c : S)
        {
            result += string( counts[c - 'a'], c );
            counts[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i)
            for (int j = 0, c = i + 'a'; j < counts[i]; ++j)
                result += c;
        return result;
    }
};