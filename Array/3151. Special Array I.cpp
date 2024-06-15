class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; ++i)
            if (nums[i] % 2 == nums[i - 1] % 2)
                return false;
        return true;
    }
};
