static int F[101][101][101];
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int result = 0;
        int const N = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        memset(F, 0, sizeof(F));
        auto calc1 = [](int x)
            {
                return (x + 1) / 2;
            };
        auto calc2 = [k](int x)
            {
                if (x >= k)
                    return x - k;
                return x;
            };
        auto update = [&result](int& x, int value) -> void
            {
                if (x < value)
                    x = value;
                result = max(result, x);
            };
        for (int i = 0; i < N; ++i)
            for(int a = 0, ae = min(i, op1); a <= ae; ++a)
                for (int b = 0, be = min(i, op2); b <= be; ++b)
                {
                    update(F[i + 1][a][b], F[i][a][b]);
                    if (a < op1)
                        update(F[i + 1][a + 1][b], F[i][a][b] + nums[i] - calc1(nums[i]));
                    if (b < op2)
                        update(F[i + 1][a][b + 1], F[i][a][b] + nums[i] - calc2(nums[i]));
                    if (a < op1 && b < op2)
                    {
                        update(F[i + 1][a + 1][b + 1], F[i][a][b] + nums[i] - calc2(calc1(nums[i])));
                        update(F[i + 1][a + 1][b + 1], F[i][a][b] + nums[i] - calc1(calc2(nums[i])));
                    }
                }
        return total - result;
    }
};
