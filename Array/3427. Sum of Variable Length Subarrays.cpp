class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
            for (int start = max(0, i - nums[i]); start <= i; ++start)
                result += nums[start];
        return result;
    }
};
