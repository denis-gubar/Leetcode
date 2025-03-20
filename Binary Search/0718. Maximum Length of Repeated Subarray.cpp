static short F[1'001][1'001];
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int const N = nums1.size(), M = nums2.size();
        memset(F, 0, sizeof(F));
        short result = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (nums1[i] == nums2[j])
                    result = max(result, F[i + 1][j + 1] = F[i][j] + 1);
        return result;
    }
};
