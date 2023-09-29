class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long result = 0;
        int N = nums.size(), a = -1, b = 0;
        while (b < N)
        {
            while (b + 1 < N && nums[b] < nums[b + 1])
                ++b;
            long long x = b - a;
            result += x * (x + 1) / 2;
            a = b;
            ++b;
        }
        return result;
    }
};
