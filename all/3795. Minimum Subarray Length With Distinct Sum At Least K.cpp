class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int const N = nums.size();
        int a = 0, b = N;
        auto check = [N, k, &nums](int m) -> bool
            {
                unordered_map<int, int> M;
                int sum = 0;
                for (int i = 0; i < N; ++i)
                {
                    if (++M[nums[i]] == 1)
                        sum += nums[i];
                    if (i >= m)
                    {
                        if (--M[nums[i - m]] == 0)
                            sum -= nums[i - m];
                    }
                    if (sum >= k)
                        return true;
                }
                return false;
            };
        if (!check(N))
            return -1;
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
