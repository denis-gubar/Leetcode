class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            if (N % (i + 1) == 0)
                result += nums[i] * nums[i];
        return result;
    }
};
