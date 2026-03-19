static int P[100'000];
class Solution {
public:
    int calc(vector<int>& nums)
    {
        int result = 3;
        int const N = nums.size();
        int HWM = 0;
        for (int i = 1; i < N; ++i)
        {
            int const delta = nums[i] - nums[i - 1];
            HWM = max(HWM, i);
            while (HWM + 1 < N && nums[HWM + 1] - nums[HWM] == delta)
                ++HWM;
            P[i - 1] = HWM;
            result = max(result, HWM - i + 2 + (HWM < N - 1 || (i > 1)));
        }
        P[N - 1] = N - 1;
        for (int i = 0; i < N - 1; ++i)
        {
            int const delta = nums[i + 1] - nums[i];
            int const j = P[i];
            if (j + 2 < N && nums[j] + 2 * delta == nums[j + 2])
            {
                result = max(result, j + 2 - i + 1);
                if (j + 3 < N && nums[j + 2] + delta == nums[j + 3])
                    result = max(result, P[j + 2] - i + 1);
            }
            if (i >= 2 && nums[i - 2] + 2 * delta == nums[i])
                result = max(result, P[i] - i + 3);
        }
        return min(N, result);
    }
    int longestArithmetic(vector<int>& nums) {
        vector<int> A(nums);
        reverse(A.begin(), A.end());
        return max(calc(nums), calc(A));
    }
};
