static int F[20][80][40][40];
class Solution {
public:
    int countSequences(vector<int>& nums, long long K) {
        int k2 = 0, k3 = 0, k5 = 0;
        while (K % 2 == 0)
            ++k2, K /= 2;
        while (K % 3 == 0)
            ++k3, K /= 3;
        while (K % 5 == 0)
            ++k5, K /= 5;
        if (K > 1)
            return 0;
        int const N = nums.size();
        int result = 0;
        memset(F, 0, sizeof(F));
        int const ZERO = 20;
        F[0][2 * ZERO][ZERO][ZERO] = 1;
        for (int i = 0; i < N; ++i)
        {
            int const a2 = (nums[i] % 4 == 0) + (nums[i] % 2 == 0);
            int const a3 = (nums[i] % 3 == 0);
            int const a5 = (nums[i] % 5 == 0);
            for(int d2 = 2 * ZERO - 2 * i; d2 <= 2 * ZERO + 2 * i; ++d2)
                for (int d3 = ZERO - i; d3 <= ZERO + i; ++d3)
                    for (int d5 = ZERO - i; d5 <= ZERO + i; ++d5)
                        if (F[i][d2][d3][d5])
                        {
                            F[i + 1][d2 + a2][d3 + a3][d5 + a5] += F[i][d2][d3][d5];
                            F[i + 1][d2][d3][d5]                += F[i][d2][d3][d5];
                            F[i + 1][d2 - a2][d3 - a3][d5 - a5] += F[i][d2][d3][d5];
                        }
        }
        return F[N][2 * ZERO + k2][ZERO + k3][ZERO + k5];
    }
};
