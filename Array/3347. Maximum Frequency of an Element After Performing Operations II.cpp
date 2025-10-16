class Solution {
public:
    int maxFrequency(vector<int>& nums, int K, int numOperations) {
        int result = 0;
        int const N = nums.size();
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        sort(nums.begin(), nums.end());
        for (int a = 0, b = 0, c = 0; b < N; ++b)
        {
            while (nums[a] + K < nums[b])
                ++a;
            while (c < N - 1 && nums[b] + K >= nums[c + 1])
                ++c;
            result = max(result, min(numOperations + M[nums[b]], c - a + 1));
        }
        for (int a = 0, b = 0; b < N; ++b)
        {
            while (1LL * nums[a] + 2 * K < nums[b])
                ++a;
            result = max(result, min(numOperations, b - a + 1));
        }
        return result;
    }
};
