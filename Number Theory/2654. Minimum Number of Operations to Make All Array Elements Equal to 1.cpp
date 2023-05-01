class Solution {
public:
    int minOperations(vector<int>& nums) {
        int M = nums.size();
        nums.resize(remove(nums.begin(), nums.end(), 1) - nums.begin());
        int N = nums.size();
        if (M > N)
            return N;
        int k = nums[0];
        for (int x : nums)
            k = gcd(k, x);
        if (k > 1)
            return -1;
        int result = 2 * N;
        for (int i = 0; i < N; ++i)
        {
            int k = nums[i];
            for (int j = i; j < N; ++j)
            {
                k = gcd(k, nums[j]);
                if (k == 1)
                {
                    result = min(result, j - i + N - 1);
                    break;
                }
            }
        }
        return result;
    }
};
