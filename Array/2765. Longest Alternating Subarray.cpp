class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int N = nums.size();
        int result = -1;
        for (int d = 0; d <= 1; ++d)
        {
            int current = 0;
            for (int i = 1; i < N; ++i)
                if (nums[i] - nums[i - 1] == 1 && i % 2 == d ||
                    nums[i] - nums[i - 1] == -1 && i % 2 == 1 - d)
                {
                    if (current == 0 && nums[i] - nums[i - 1] != 1)
                        continue;
                    ++current;
                }
                else
                {
                    if (current > 0)
                        result = max(result, current + 1);
                    current = 0;
                }
            if (current > 0)
                result = max(result, current + 1);
        }
        return result;
    }
};
