class Solution {
public:
    vector<string> split( const string& s, char delimeter = ' ' )
    {
        vector<string> result;
        istringstream ss( s );
        for (string token; !ss.eof(); )
        {
            getline( ss, token, delimeter );
            result.push_back( token );
        }
        return result;
    }
    string toGoatLatin( string S ) {
        string result;
        string vowels{"aeiouAEIOU"};
        vector<string> words = split( S );
        for (int i = 0; i < words.size(); ++i)
        {
            if (vowels.find( words[i][0] ) != string::npos)
                words[i] += "ma";
            else
                words[i] = words[i].substr( 1 ) + words[i][0] + "ma";
            words[i] += string( i + 1, 'a' );
            result += ' ' + words[i];
        }
        return result.substr(1);
    }
};