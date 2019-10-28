class Solution {
public:
    vector<vector<int>> largeGroupPositions( string S ) {
        vector<vector<int>> result;
        S = " " + S + " ";
        int start = 0, end = 0;
        for (int i = 1; i < S.size(); ++i)
        {
            if (S[i] != S[i - 1])
            {
                if (end - start >= 2)
                    result.push_back( { start - 1, end - 1 } );
                start = end = i;
            }
            else
                end = i;
        }
        return result;
    }
};