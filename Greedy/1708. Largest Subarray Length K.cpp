class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int N = nums.size();
        auto it = max_element(nums.begin(), nums.begin() + N - k + 1);
        return vector<int>(it, it + k);
    }
};
