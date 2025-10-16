class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0;
        int d = 1;
        for (int x : nums)
            result += d * x, d *= -1;
        return result;
    }
};
