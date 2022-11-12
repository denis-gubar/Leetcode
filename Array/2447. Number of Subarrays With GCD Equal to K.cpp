class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int N = nums.size();
        int result = 0;
        for (int start = 0; start < N; ++start)
        {
            for (int end = start, g = nums[start]; g % k == 0 && end < N; ++end)
            {
                g = gcd(g, nums[end]);
                if (g == k)
                    ++result;
            }
        }
        return result;
    }
};
