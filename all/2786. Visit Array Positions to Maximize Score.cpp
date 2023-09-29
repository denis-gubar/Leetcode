class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int N = nums.size();
        vector<long long> F(2);
        long long result = nums[0];
        for (int i = N - 1; i >= 0; --i)
        {
            long long y = nums[i];
            result = nums[i] + max(F[y % 2], F[1 - y % 2] - x);
            F[y % 2] = max(F[y % 2], result);
        }
        return result;
    }
};
