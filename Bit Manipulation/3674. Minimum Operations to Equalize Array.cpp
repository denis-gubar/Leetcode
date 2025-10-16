class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool isEqual = true;
        int f = nums[0];
        for (int x : nums)
            isEqual &= f == x;
        return 1 - isEqual;
    }
};
