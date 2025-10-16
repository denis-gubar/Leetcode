static int MOD = 1'000'000'007;
static int F[100'001][3][3][3];
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        memset(F, 0, sizeof(F));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0; i < N; ++i)
        {
            int const p = nums[i] % 2;
            for(int a = 0; a < 3; ++a)
                for(int b = 0; b < 3; ++b)
                    for (int c = 0; c < 3; ++c)
                    {
                        if (a == b && b == c && a < 3)
                            continue;
                        add(F[i + 1][a][b][c], F[i][a][b][c]);
                        add(F[i + 1][p][a][b], F[i][a][b][c]);
                    }
            add(F[i + 1][p][2][2], 1);
        }
        for (int a = 0; a < 2; ++a)
            for (int b = 0; b < 3; ++b)
                for (int c = 0; c < 3; ++c)
                {
                    if (a == b && b == c)
                        continue;
                    add(result, F[N][a][b][c]);
                }
        return result;
    }
};
