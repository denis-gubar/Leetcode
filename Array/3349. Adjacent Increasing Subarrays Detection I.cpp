class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int const N = nums.size();
        for (int a = 0; a + 2 * k <= N; ++a)
        {
            bool isOk = true;
            for (int i = 1; i < k; ++i)
                isOk &= nums[a + i - 1] < nums[a + i];
            if (!isOk) continue;
            int b = a + k;
            {
                isOk = true;
                for (int i = 1; i < k; ++i)
                    isOk &= nums[b + i - 1] < nums[b + i];
                if (isOk)
                    return true;
            }
        }
        return false;
    }
};
