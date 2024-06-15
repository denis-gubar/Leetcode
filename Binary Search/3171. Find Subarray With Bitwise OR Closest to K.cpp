static int F[100'002][18];
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int result = 1 << 30;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = F[i][j - 1] & F[i + (1 << (j - 1))][j - 1];
        auto rmq = [](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return F[L][j] & F[R - (1 << j) + 1][j];
            };
        auto calc = [&rmq, N, k](int i)
            {
                int a = i, b = N;
                if (k <= rmq(i, b - 1))
                    return rmq(i, b - 1) - k;
                if (k >= rmq(i, i))
                    return k - rmq(i, i);
                int m = 0;
                while (a < b)
                {
                    m = (a + b) / 2;
                    int r = rmq(i, m);
                    if (r == k)
                        return 0;
                    if (k < r)
                    {
                        if (m < N - 1 && k > rmq(i, m + 1))
                            return min(abs(rmq(i, m) - k), abs(rmq(i, m + 1) - k));
                        a = m + 1;
                    }
                    else
                    {
                        if (m > 0 && k < rmq(i, m - 1))
                            return min(abs(rmq(i, m) - k), abs(rmq(i, m - 1) - k));
                        b = m;
                    }
                }
                return rmq(i, m);
            };
        for (int i = 0; i < N; ++i)
            result = min(result, calc(i));
        return result;
    }
};
