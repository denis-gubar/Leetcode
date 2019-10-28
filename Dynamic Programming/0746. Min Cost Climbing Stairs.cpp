class Solution {
public:
    int minCostClimbingStairs( vector<int>& cost ) {
        int n = cost.size();
        vector<int> result( n );
        result[0] = cost[0];
        result[1] = cost[1];
        for (int i = 2; i < n; ++i)
            result[i] = min( result[i - 2], result[i - 1] ) + cost[i];
        return min(result[n - 1], result[n - 2]);
    }
};