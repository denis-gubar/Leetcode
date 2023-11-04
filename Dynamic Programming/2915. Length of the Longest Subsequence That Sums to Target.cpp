static int F[1'001][1'001];
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int N = nums.size();
        memset(F, -1, sizeof(F));
        F[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= target; ++j)
                if (F[i][j] >= 0)
                {
                    F[i + 1][j] = max(F[i + 1][j], F[i][j]);
                    if (j + nums[i] <= target)
                        F[i + 1][j + nums[i]] = max(F[i + 1][j + nums[i]], F[i][j] + 1);
                }
        return F[N][target];
    }
};
