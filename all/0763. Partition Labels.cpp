class Solution {
public:
    vector<int> partitionLabels( string S ) {
        vector<int> result;
        vector<int> B( 255, -1 ), E( 255, -1 );
        for (char c = 'a'; c <= 'z'; ++c)
        {
            for(int i = 0; i < S.size(); ++i)
                if (S[i] == c)
                {
                    if (B[c] < 0)
                        B[c] = i;
                    E[c] = i;
                }
        }
        vector<pair<int, int>> P;
        for (char c = 'a'; c <= 'z'; ++c)
            if (B[c] >= 0)
                P.push_back( { B[c], E[c] } );
        sort( P.begin(), P.end() );
        vector<bool> isVisited( P.size() );
        vector<pair<int, int>> X;
        int a = -1, b = -1;
        for (int i = 0; i < P.size(); ++i)
        {
            if (!isVisited[i])
            {
                if ( a >= 0 )
                    X.push_back( { a, b } );
                isVisited[i] = true;
                a = P[i].first;
                b = P[i].second;
                int j = i + 1;
                while (j < P.size() && P[j].first <= b)
                {
                    isVisited[j] = true;
                    b = max(b, P[j].second);
                    ++j;
                }
            }
        }
        if (a >= 0)
            X.push_back( { a, b } );
        for (const auto& x : X)
            result.push_back( x.second - x.first + 1 );
        return result;
    }
};