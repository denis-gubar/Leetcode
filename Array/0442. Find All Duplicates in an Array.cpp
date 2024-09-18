class Solution {
public:
    vector<int> findDuplicates( vector<int>& nums ) {
        vector<int> result;        
        result.reserve( nums.size() );
        for( int x : nums )
        {
            if ( nums[abs(x) - 1] < 0 )
                result.push_back(abs(x));
            nums[abs(x) - 1] *= -1;
        }
        return result;
    }
};