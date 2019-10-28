class Solution {
public:
    bool pyramidTransition( string bottom, vector<string>& allowed ) {
        int n = bottom.size();
        vector<string> S;
        for (int i = 0; i < n; ++i)
            S.push_back( string(1, bottom[i]) );
        while (S.size() > 1)
        {
            vector<string> X;
            X.swap( S );
            for (int i = 0; i + 1 < X.size(); ++i)
            {
                string current = "";
                for (const auto& a : allowed)
                    if (X[i].find( a[0] ) != string::npos && X[i + 1].find( a[1] ) != string::npos)
                        current += string( 1, a[2] );
                sort( current.begin(), current.end() );
                current.erase( unique( current.begin(), current.end() ), current.end() );
                S.push_back( current );
                if (current.empty())
                    return false;
            }
        }
        return true;
    }
};