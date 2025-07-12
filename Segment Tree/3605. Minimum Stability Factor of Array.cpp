static int F[100'002][18];
static int Right[100'000];
class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
        int const N = nums.size();
        int bigCount = 0;
        for (int x : nums)
            bigCount += x > 1;
        if (bigCount <= maxC)
            return 0;
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = gcd(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto calcGCD = [](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return gcd(F[L][j], F[R - (1 << j) + 1][j]);
            };
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] == 1)
            {
                Right[i] = 0;
                continue;
            }
            int a = i, b = N;
            while (a + 1 < b)
            {
                int m = (a + b) / 2;
                if (calcGCD(i, m) > 1)
                    a = m;
                else
                    b = m;
            }
            Right[i] = a;
        }
        auto calc = [&nums, N, maxC](int m) -> bool
            {
                int count = maxC;
                for (int i = 0; i < N; ++i)
                {
                    if (Right[i] < i + m)
                        continue;
                    if (count == 0)
                        return false;
                    --count;
                    i = i + m;
                }
                return true;
            };
        int a = 0, b = N;
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
