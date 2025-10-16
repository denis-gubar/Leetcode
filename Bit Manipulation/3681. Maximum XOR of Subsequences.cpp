class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int const N = nums.size();
        int result = 0;
        int index = 0;
        for (int i = 30; i >= 0; --i)
        {
            int maxIndex = index;
            int best = -1;
            for (int j = index; j < N; ++j)
            {
                if ((nums[j] & (1 << i)) != 0 && nums[j] > best)
                    best = nums[j], maxIndex = j;
            }

            if (best == -1)
                continue;

            swap(nums[index], nums[maxIndex]);

            maxIndex = index;

            for (int j = 0; j < N; ++j)
                if (j != maxIndex && (nums[j] & (1 << i)) != 0)
                    nums[j] ^= nums[maxIndex];
            ++index;
        }
        for (int i = 0; i < N; i++)
            result ^= nums[i];
        return result;
    }
};
