class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<vector<int>> F(2, vector<int>(10'001));
        vector<int> M(10'001);
        for (int x : nums)
            M[x] += x;
        for (int i = 1; i <= 10'000; ++i)
        {
            F[0][i] = max(F[0][i - 1], F[1][i - 1]);
            if (M[i] > 0)
                F[1][i] = F[0][i - 1] + M[i];
        }
        return max(F[0][10'000], F[1][10'000]);
    }
};
