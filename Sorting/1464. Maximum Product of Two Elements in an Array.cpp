class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        return (nums[N - 2] - 1) * (nums[N - 1] - 1);
    }
};