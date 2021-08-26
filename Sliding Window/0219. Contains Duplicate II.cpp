class Solution {
public:
    bool containsNearbyDuplicate( vector<int>& nums, int k ) {
        vector<pair<int, int>> P;
        for (int i = 0; i < nums.size(); ++i)
            P.push_back( { nums[i], i } );
        sort( P.begin(), P.end() );
        for (int i = 1; i < nums.size(); ++i)
            if (P[i].first == P[i - 1].first && P[i].second - P[i - 1].second <= k)
                return true;
        return false;
    }
};
