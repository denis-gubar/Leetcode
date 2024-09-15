static int F[100'002][18];
static int M[100'001];
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        memset(M, 0, sizeof(M));
        for (int i = N - 1; i >= 0; --i)
            M[nums[i]] = i;
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto rmq = [](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F[L][j], F[R - (1 << j) + 1][j]);
            };
        int pos = N - 1;
        while (pos > 0)
        {
            int L = M[rmq(0, pos - 1)];
            result += 1LL * (pos - L) * nums[L];
            pos = L;
        }
        return result;
    }
};
