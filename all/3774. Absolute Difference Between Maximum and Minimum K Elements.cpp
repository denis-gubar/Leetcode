class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int const N = nums.size();
        int a = 0, b = 0;
        for(int i = 0; i < k; ++i)
            a += nums[i], b += nums[N - 1 - i];
        return abs(a - b);
    }
};