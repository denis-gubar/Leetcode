class Solution {
public:
    vector<int> grayCode( int n ) {
        vector<int> result;
        result.push_back( 0 );
        if (n == 0)
            return result;
        result.push_back( 1 );
        for (int i = 1; i < n; ++i)
        {
            for (int k = result.size() - 1; k >= 0; --k)
                result.push_back( result[k] ^ (1 << i) );
        }
        return result;
    }
};