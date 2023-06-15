class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        int pos = find(nums.begin(), nums.end(), 1) - nums.begin();
        for (int i = pos; i > 0; --i)
        {
            swap(nums[i - 1], nums[i]);
            ++result;
        }
        pos = find(nums.begin(), nums.end(), N) - nums.begin();
        for (int i = pos; i < N - 1; ++i)
        {
            swap(nums[i], nums[i + 1]);
            ++result;
        }
        return result;
    }
};
