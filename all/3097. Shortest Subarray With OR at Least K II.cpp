static int F[200'002][19];
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int total = 0, N = nums.size();
        for (int x : nums)
        {
            if (x >= k)
                return 1;
            total |= x;
        }
        if (total < k)
            return -1;
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = F[i][j - 1] | F[i + (1 << (j - 1))][j - 1];
        auto rmq = [N](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return F[L][j] | F[R - (1 << j) + 1][j];
            };
        int a = 0, b = N;
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            bool flag = false;
            for (int start = 0; start + m <= N; ++start)
                if (rmq(start, start + m - 1) >= k)
                {
                    flag = true;
                    break;
                }
            if (flag)
                b = m;
            else
                a = m;
        }
        return b;
    }
};
