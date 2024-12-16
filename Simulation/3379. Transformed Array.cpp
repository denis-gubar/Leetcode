class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int const N = nums.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i)
            result[i] = nums[(i + nums[i] + N * 1000) % N];
        return result;
    }
};
