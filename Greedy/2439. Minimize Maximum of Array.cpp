class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int N = nums.size();
        int a = -1, b = 1'000'000'000;
        auto calc = [N, &nums](int m)
        {
            vector<long long> A;
            for (int x : nums)
                A.push_back(x);
            for (int i = N - 1; i > 0; --i)
                if (A[i] > m)
                {
                    long long delta = A[i] - m;
                    A[i] -= delta;
                    A[i - 1] += delta;
                }
            return A[0] <= m;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        int result = b;
        return result;
    }
};

