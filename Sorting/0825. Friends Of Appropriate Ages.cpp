class Solution {
public:
    int numFriendRequests( vector<int>& ages ) {
        int result = 0;
        sort( ages.begin(), ages.end() );
        for (int i = 0; i < ages.size(); ++i)
            ages[i] *= 2;
        for (int i = 0; i < ages.size(); ++i)
        {
            auto start = lower_bound( ages.begin(), ages.end(), ages[i] / 2 + 15 );
            auto end = lower_bound( ages.begin(), ages.end(), ages[i] + 1 );
            --end;
            if (start <= end)
                result += distance( start, end );            
        }
        return result;
    }
};