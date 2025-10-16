class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int N = nums.size();
        int result = N;
        int best = 200'000;
        long long left = accumulate(nums.begin(), nums.end(), 0LL);
        int L = N, R = 0;
        long long right = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            long long x = 0, y = 0;
            if (L > 0)
                x = left / L;
            if (R > 0)
                y = right / R;
            long long current = abs(x - y);
            if (current <= best)
            {
                best = current;
                result = i;
            }
            left -= nums[i];
            right += nums[i];
            --L, ++R;
        }
        return result;
    }
};
