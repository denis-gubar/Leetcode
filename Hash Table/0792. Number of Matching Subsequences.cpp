class Solution {
public:
    int numMatchingSubseq( string S, vector<string>& words ) {
        int result = 0;
        vector<vector<int>> indexes(26);
        for (int i = 0; i < S.size(); ++i)
            indexes[S[i] - 'a'].push_back( i );
        for (const string& w : words)
        {
            int a = 0, b = 0;
            while (b < w.size())
            {
                auto it = lower_bound( indexes[w[b] - 'a'].begin(), indexes[w[b] - 'a'].end(), a );
                if (it == indexes[w[b] - 'a'].end())
                    break;
                a = *it + 1;
                ++b;
            }
            result += b == w.size();
        }
        return result;
    }
};