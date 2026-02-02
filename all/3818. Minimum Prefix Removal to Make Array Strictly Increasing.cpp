class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int const N = nums.size();
        int result = N - 1;
        for (int i = N - 1; i > 0; --i, --result)
            if (nums[i - 1] >= nums[i])
                break;
        return result;
    }
};
