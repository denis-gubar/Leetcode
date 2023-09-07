int static F[101][4];
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int N = nums.size();
        memset(F, 101, sizeof(F));
        F[0][0] = 0;
        for (int i = 0; i < N; ++i)
            for(int j = 0; j < 4; ++j)
                if (F[i][j] < N)
                    for (int k = max(1, j); k < 4; ++k)
                        F[i + 1][k] = min(F[i + 1][k], F[i][j] + (nums[i] != k));
        return min({ F[N][1], F[N][2], F[N][3] });
    }
};
