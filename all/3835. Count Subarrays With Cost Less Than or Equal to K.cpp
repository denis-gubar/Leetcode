static int F1[100'001][18];
static int F2[100'001][18];
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long K) {
        long long result = 0;
        int const N = nums.size();
        memset(F1, 0, sizeof(F1));
        memset(F2, 0, sizeof(F2));
        for (int i = 0; i < N; ++i)
            F1[i][0] = F2[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
            {
                F1[i][j] = min(F1[i][j - 1], F1[i + (1 << (j - 1))][j - 1]);
                F2[i][j] = max(F2[i][j - 1], F2[i + (1 << (j - 1))][j - 1]);
            }
        auto rmq1 = [](int L, int R)
            {
                if (L == R)
                    return F1[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return min(F1[L][j], F1[R - (1 << j) + 1][j]);
            };
        auto rmq2 = [](int L, int R)
            {
                if (L == R)
                    return F2[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F2[L][j], F2[R - (1 << j) + 1][j]);
            };
        auto calc = [&rmq1, &rmq2](int L, int R)
            {
                return rmq2(L, R) - rmq1(L, R);
            };
        bool flag = true;
        int i = 0;
        for (; flag && i < N; ++i)
        {
            if (1LL * calc(i, N - 1) * (N - i) <= K)
            {
                flag = false;
                break;
            }
            int a = i, b = N;
            while (a + 1 < b)
            {
                int m = (a + b) / 2;
                if (1LL * calc(i, m) * (m - i + 1) <= K)
                    a = m;
                else
                    b = m;
            }
            result += a - i + 1;
        }
        if (!flag)
            for (; i < N; ++i)
                result += N - i;
        return result;
    }
};
