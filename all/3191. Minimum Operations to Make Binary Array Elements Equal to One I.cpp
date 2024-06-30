class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        for(int i = 0; i < N - 2; ++i)
            if (nums[i] == 0)
            {
                ++result;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
        if (nums[N - 2] != 1 || nums[N - 1] != 1)
            return -1;
        return result;
    }
};
