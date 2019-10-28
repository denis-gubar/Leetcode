class Solution {
public:
    string maskPII( string S ) {
        string result;
        if (isalpha( S[0] ))
        {
            result = S;
            for (int i = 0; i < S.size(); ++i)
                result[i] = tolower( result[i] );
            result.erase( result.begin() + 1, result.begin() + result.find( '@' ) - 1 );
            result.insert( 1, "*****" );
        }
        else
        {
            for (int i = 0; i < S.size(); ++i)
                if (isdigit( S[i] ))
                    result += S[i];
            string prefix = "";
            if (result.size() > 10)
            {
                prefix = "+" + string( result.size() - 10, '*' ) + "-";
                result = result.substr( result.size() - 10 );
            }
            result.insert( result.begin() + 3, '-' );
            result.insert( result.begin() + 7, '-' );
            for (int i = 0; i < 3; ++i)
                result[i] = '*';
            for (int i = 4; i < 7; ++i)
                result[i] = '*';
            result = prefix + result;
        }
        return result;
    }
};