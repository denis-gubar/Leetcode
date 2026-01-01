class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long result = min(1LL * need1 * cost1 + 1LL * need2 * cost2,
            1LL * max(need1, need2) * costBoth);
        if (costBoth < cost1 + cost2)
        {
            if (need1 <= need2)
                result = min(result, 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1));
            else
                result = min(result, 1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2));
        }
        return result;
    }
};
