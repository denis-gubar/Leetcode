class Solution {
public:
    int minRemoval(vector<int>& nums, int K) {
        int const N = nums.size();
        int result = N - 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 1; ++i)
        {
            int const L = nums.end() - upper_bound(nums.begin() + i, nums.end(), 1LL * K * nums[i]) + i;
            result = min(result, L);
        }
        return result;
    }
};
