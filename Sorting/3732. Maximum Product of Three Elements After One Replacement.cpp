class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long const INF = 100'000;
        sort(nums.begin(), nums.end(), [](int a, int b)
            {
                return abs(a) > abs(b);
            });
        return abs(INF * nums[0] * nums[1]);
    }
};
