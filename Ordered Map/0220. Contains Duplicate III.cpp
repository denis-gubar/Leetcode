class Solution {
public:
    bool containsNearbyAlmostDuplicate( vector<int>& nums, int k, int t ) {
        vector<pair<long long, long long>> P;
        for (int i = 0; i < nums.size(); ++i)
            P.push_back( { nums[i], i } );
        sort( P.begin(), P.end() );
        for (int i = 0; i + 1 < nums.size(); ++i)
            for (int j = i + 1; j < nums.size() && P[j].first - P[i].first <= t; ++j)
                if (abs( P[i].second - P[j].second ) <= k)
                    return true;
        return false;
    }
};