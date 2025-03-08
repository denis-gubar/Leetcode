class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        int last = nums[0];
        for (int x : nums)
            if (last != x)
                ++result, last = x;
        return result;
    }
};
