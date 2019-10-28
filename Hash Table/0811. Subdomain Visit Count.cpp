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
    vector<string> subdomainVisits( vector<string>& cpdomains ) {
        vector<string> result;
        map<string, int> counts;
        for (int i = 0; i < cpdomains.size(); ++i)
        {
            vector<string> A = split( cpdomains[i], ' ' );
            int x = stoi( A[0] );
            vector<string> S = split( A[1], '.' );
            if (S.size() == 1)
                counts[S[0]] += x;
            if (S.size() == 2)
                counts[S[0] + "." + S[1]] += x, counts[S[1]] += x;
            if (S.size() == 3)
                counts[S[0] + "." + S[1] + "." + S[2]] += x, counts[S[1] + "." + S[2]] += x, counts[S[2]] += x;
        }
        for (const auto& p : counts)
            result.push_back( to_string( p.second ) + " " + p.first );
        return result;
    }
};
