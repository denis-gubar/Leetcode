class Solution {
public:
    vector<vector<int>> generate( int numRows ) {
        vector<vector<int>> result;
        if (numRows > 0)
        {
            result.push_back( {1} );
            for (int i = 1; i < numRows; ++i)
            {
                vector<int> current{ 1 };
                for (int k = 0; k + 1 < i; ++k)
                    current.push_back( result.back()[k] + result.back()[k + 1] );
                current.push_back( 1 );
                result.push_back( current );
            }
        }
        return result;
    }
};