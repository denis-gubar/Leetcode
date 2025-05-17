static short F[501][501];
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int const N = nums1.size(), M = nums2.size();
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                F[i + 1][j + 1] = max<int>({ F[i][j] + (nums1[i] == nums2[j]), F[i + 1][j], F[i][j + 1] });
        return F[N][M];
    }
};
