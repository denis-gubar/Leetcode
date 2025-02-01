static int F[100'001][51][3];
class Solution {
public:
    int maxFrequency(vector<int>& nums, int K) {
        int result = 0;
        int const N = nums.size();
        memset(F, 0, sizeof(F));
        auto update = [&result](int& x, int value)
            {
                if (x < value)
                    x = value;
                if (result < x)
                    result = x;
            };
        for (int i = 0; i < N; ++i)
            for (int j = 1; j < 51; ++j)
            {
                update(F[i + 1][j][0], F[i][j][0] + (nums[i] == K));
                update(F[i + 1][j][1], F[i][j][1] + (nums[i] == j));
                update(F[i + 1][nums[i]][1], F[i][j][0] + 1);
                update(F[i + 1][j][2], F[i][j][1] + (nums[i] == K));
                update(F[i + 1][j][2], F[i][j][2] + (nums[i] == K));
            }
        return result;
    }
};
