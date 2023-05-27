class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        result[N - 1] = 1;
        for (int i = N - 2; i >= 0; --i)
            result[i] = result[i + 1] * nums[i + 1];
        int prefix = 1;
        for (int i = 0; i < N - 1; ++i)
        {
            prefix *= nums[i];
            result[i + 1] *= prefix;
        }
        return result;
    }
};
