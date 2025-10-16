class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int K) {
        sort(nums.begin(), nums.end(), greater{});
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        if (nums.size() > K)
            nums.resize(K);
        return nums;
    }
};
