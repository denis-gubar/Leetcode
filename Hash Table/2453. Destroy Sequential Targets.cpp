class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int N = nums.size();
        int result = 1 << 30;
        int best = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
            ++M[nums[i] % space];
        for(auto [key, value]: M)
            if (value > best)
                best = value;
        for (int i = 0; i < N; ++i)
            if (M[nums[i] % space] == best)
                result = min(result, nums[i]);
        return result;
    }
};
