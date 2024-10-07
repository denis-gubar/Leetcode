class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int& x : nums)
            x = a * x * x + b * x + c;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
