class Solution {
public:
    static int const MOD = 1'000'000'007;
    int minCostToEqualizeArray(vector<int>& nums, long long cost1, long long cost2) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        long long const TOP = nums.back();
        long long const MIN = nums[0];
        if (MIN == TOP)
            return 0;
        if (N == 2)
            return cost1 * (TOP - MIN) % MOD;
        long long total = 0;
        for (int x : nums)
            total += x;
        auto calc = [MIN, N, total, cost1, cost2](long long TOP)
            {
                long long result = (N * TOP - total) * cost1;
                long long rest = (N - 1) * TOP - (total - MIN);
                if (rest >= TOP - MIN - 1)
                {
                    long long delta = N * TOP - total;
                    return min(result, delta / 2 * cost2 + delta % 2 * cost1);
                }
                return min(result, rest * cost2 + (TOP - MIN - rest) * cost1);
            };
        long long result = calc(TOP);
        for (long long x = TOP + 1; x <= TOP + 1'000'000; ++x)
            result = min(result, calc(x));
        return result % MOD;
    }
};
