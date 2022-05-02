class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int result = -1;
        int N = nums.size();
        if (N == 1 && k % 2 == 1)
            return -1;
        if (k == 1)
            return nums[1];
        result = nums[0];
        for (int i = 0; i < min(N, k - 1); ++i)
            result = max(result, nums[i]);
        if (k < N)
            result = max(result, nums[k]);
        return result;
    }
};
