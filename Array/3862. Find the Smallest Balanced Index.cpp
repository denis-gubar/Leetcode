class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int result = -1;
        int const N = nums.size();
        if (N == 2 && nums[0] == 1)
            return 1;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        total -= nums.back();
        long long prod = 1;
        for (int i = N - 2; i >= 0; --i)
        {
            total -= nums[i];
            if (0.9 * prod * nums[i + 1] > total)
                break;
            prod *= nums[i + 1];
            if (total == prod)
                result = i;
        }
        return result;
    }
};
