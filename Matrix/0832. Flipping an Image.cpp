class Solution {
public:
    vector<vector<int>> flipAndInvertImage( vector<vector<int>>& A ) {
        vector<vector<int>> result( A );
        for(int i = 0; i < result.size(); ++i)
            reverse( result[i].begin(), result[i].end() );
        for (int i = 0; i < result.size(); ++i)
            for (int j = 0; j < result[0].size(); ++j)
                result[i][j] = 1 - result[i][j];
        return result;
    }
};