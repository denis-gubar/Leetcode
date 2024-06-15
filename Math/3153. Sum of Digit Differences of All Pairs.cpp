static long long F[10][10];
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i];
            int pos = 0;
            while (x > 0)
            {
                int d = x % 10;
                ++F[pos][d];
                ++pos;
                x = x / 10;
            }
        }
        for(int pos = 0; pos < 10; ++pos)
            for(int d = 0; d < 10; ++d)
                if (F[pos][d] > 0)
                    result += (N - F[pos][d]) * F[pos][d];
        return result / 2;
    }
};
