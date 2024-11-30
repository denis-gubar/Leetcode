class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        if (N == 1) return result;
        auto it = min_element(nums.begin(), nums.end());
        result += it - nums.begin();
        rotate(nums.begin(), it, next(it));
        auto rit = max_element(nums.rbegin(), nums.rend());
        result += rit - nums.rbegin();
        return result;
    }
};
