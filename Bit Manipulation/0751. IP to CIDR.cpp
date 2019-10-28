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

class Solution {
public:
    vector<string> ipToCIDR( string ip, int range ) {
        vector<string> result;
        vector<string> S( split( ip, '.' ) );
        vector<int> A;
        long long x = 0;
        for (const auto& s : S)
        {
            int t = stoi( s );
            x = (x << 8) + t;
            A.push_back( t );
        }
        long long end = x + range;
        while (x < end)
        {
            int k = 0;
            while (true)
            {
                long long mask = (1LL << 32) - (1LL << k);
                if ((mask & x) != x || x + (1LL << k) > end)
                    break;
                ++k;
            }
            --k;
            A = vector<int>(4);
            long long t = x;
            for (int i = 0; i < 4; ++i)
            {
                A[3 - i] = t % 256;
                t >>= 8;
            }
            string current = to_string( A[0] ) + "." + to_string( A[1] ) + "." + to_string( A[2] ) + "." + to_string( A[3] ) + "/" + to_string( 32 - k );
            x += (1 << k);
            result.push_back( current );
        }

        return result;
    }
};