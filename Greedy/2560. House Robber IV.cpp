class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int N = nums.size();
        int a = 0, b = 1'000'000'000;
        auto check = [&nums, k, N](int m)
        {
            int F0 = 0, F1 = 0;
            for (int i = 0; i < N; ++i)
            {
                int nF0 = max(F0, F1);
                int nF1 = (nums[i] <= m) + F0;
                F0 = nF0, F1 = nF1;
            }
            return F0 >= k || F1 >= k;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (check(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
