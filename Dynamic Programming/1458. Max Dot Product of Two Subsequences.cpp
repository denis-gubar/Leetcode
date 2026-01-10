class Solution {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {		
		int N = nums1.size(), M = nums2.size();
        bool isPos1 = true, isNeg1 = true;
        bool isPos2 = true, isNeg2 = true;
        for(int x: nums1)
            isPos1 &= x > 0, isNeg1 &= x < 0;
        for(int x: nums2)
            isPos2 &= x > 0, isNeg2 &= x < 0;
        if (isPos1 && isNeg2)
            return *min_element(nums1.begin(), nums1.end()) * *max_element(nums2.begin(), nums2.end());
        if (isPos2 && isNeg1)
            return *max_element(nums1.begin(), nums1.end()) * *min_element(nums2.begin(), nums2.end());
		vector<vector<int>> F(N + 2, vector<int>(M + 2, -(1 << 30)));
		for (int i = 0; i <= N; ++i)
			F[i][0] = 0;
		for (int j = 0; j <= M; ++j)
			F[0][j] = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				F[i + 1][j + 1] = max({F[i + 1][j + 1], F[i][j] + nums1[i] * nums2[j], F[i][j + 1], F[i + 1][j]});
		return F[N][M];
	}
};