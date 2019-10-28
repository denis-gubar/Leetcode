class Solution {
public:
    string reorganizeString( string S ) {
        vector<int> A(256);
        set<pair<int, char>> X;
        for (char c : S)
            ++A[c];
        for (char c = 'a'; c <= 'z'; ++c)
            if (A[c])
                X.insert( { -A[c], c } );
        auto it = X.begin();
        string result = " ";
        while (it != X.end())
        {
            if (it->second == result.back())
                ++it;
            if (it == X.end())
                return "";
            result += it->second;
            auto P = *it;
            X.erase( it );
            if (P.first + 1)
                X.insert( { P.first + 1, P.second } );
            it = X.begin();
        }
        return result.substr( 1 );
    }
};