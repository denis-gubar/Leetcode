class Solution {
public:
    string replace_all( const string& s, const string& what, const string& to )
    {
        string result;
        int start = 0;
        for (int finish = s.find( what ); finish != string::npos; finish = s.find( what, start ))
        {
            result.append( s, start, finish - start ).append( to );
            start = finish + what.size();
        }
        result.append( s, start, s.size() - start );
        return result;
    }
    vector<string> split( const string& s, const vector<string>& banned, char delimeter = ' ' )
    {
        vector<string> result;
        istringstream ss( s );
        for (string token; !ss.eof(); )
        {
            getline( ss, token, delimeter );
            if (!token.empty() && find( banned.begin(), banned.end(), token) == banned.end() )
                result.push_back( token );
        }
        return result;
    }
    string mostCommonWord( string paragraph, vector<string>& banned ) {
        paragraph = replace_all( paragraph, "!", " " );
        paragraph = replace_all( paragraph, "?", " " );
        paragraph = replace_all( paragraph, "'", " " );
        paragraph = replace_all( paragraph, ",", " " );
        paragraph = replace_all( paragraph, ";", " " );
        paragraph = replace_all( paragraph, ".", " " );        
        for (char& c : paragraph)
            c = tolower( c );
        vector<string> S = split( paragraph, banned );
        map<string, int> M;
        for (const string& s : S)
            ++M[s];
        int count = 0;
        string result = "";
        for (const auto& m : M)
            if (m.second > count)
                count = m.second, result = m.first;
        return result;
    }
};