class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int N = nums.size();
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        vector<long long> A(1'000'002);
        for (int i = 0; i < N; ++i)
            A[nums[i]] += 2 * cost[i];
        long long current = 0;
        for (int i = 0; i < N; ++i)
            current += 1LL * cost[i] * (nums[i] - a);
        long long result = current;
        long long delta = -accumulate(cost.begin(), cost.end(), 0LL);
        for (int x = a; x <= b; ++x)
        {
            result = min(result, current);
            delta += A[x];
            current += delta;
        }
        return result;
    }
};
