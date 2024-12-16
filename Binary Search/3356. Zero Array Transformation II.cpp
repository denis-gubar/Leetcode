class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        auto calc = [&nums, &queries, N](int K)
            {
                vector<int> A(N + 1);
                for (int i = 0; i < K; ++i)
                {
                    int const& L = queries[i][0];
                    int const& R = queries[i][1];
                    int const& VAL = queries[i][2];
                    A[L] -= VAL, A[R + 1] += VAL;
                }
                int balance = 0;
                for (int i = 0; i < N; ++i)
                {
                    balance += A[i];
                    if (nums[i] + balance > 0)
                        return false;
                }
                return true;
            };
        if (calc(0)) return 0;
        if (!calc(Q)) return -1;
        int a = 0, b = Q;
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
