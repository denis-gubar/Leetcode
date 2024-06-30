class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 1 << 30;
        int N = nums.size();
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            result = min(result, nums[a] + nums[b]);
        return 0.5 * result;
    }
};
