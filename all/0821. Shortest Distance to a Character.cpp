class Solution {
public:
    vector<int> shortestToChar( string S, char C ) {
        vector<int> result(S.size());
        vector<int> positions;
        for (int i = 0; i < S.size(); ++i)
            if (S[i] == C)
                positions.push_back( i );
        for (int i = 0; i < S.size(); ++i)
        {
            auto it = lower_bound( positions.begin(), positions.end(), i );
            int k = -S.size();
            if (it != positions.end())
                k = *it;
            int nk = k;
            if (it != positions.begin())
                nk = *(--it);
            result[i] = min( abs( k - i ), abs( nk - i ) );
        }
        return result;
    }
};