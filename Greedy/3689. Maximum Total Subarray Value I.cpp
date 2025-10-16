class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int K) {
        return 1LL * K * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
};
