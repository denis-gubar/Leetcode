class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = nums[0];
        for (int x : nums)
            if (abs(result) > abs(x))
                result = x;
            else if (result == -x && result < 0)
                result = x;
        return result;
    }
};
