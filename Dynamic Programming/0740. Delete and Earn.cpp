static int F[20'001];
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int const N = nums.size();
        F[0] = 0;
        F[1] = nums[0] * M[nums[0]];
        for (int i = 1; i < N; ++i)
            F[i + 1] = max(F[i - 1] + nums[i] * M[nums[i]], F[i] + (nums[i - 1] + 1 == nums[i] ? 0 : nums[i] * M[nums[i]]));
        return F[N];
    }
};
