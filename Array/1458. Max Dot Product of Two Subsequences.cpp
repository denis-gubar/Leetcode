class Solution {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		int result = 0;
		int A = *max_element(nums1.begin(), nums1.end());
		int a = *min_element(nums1.begin(), nums1.end());
		int B = *max_element(nums2.begin(), nums2.end());
		int b = *min_element(nums2.begin(), nums2.end());
		vector<int> X{ A * B, A * b, a * b, a * B };
		result = *max_element(X.begin(), X.end());
		if (result < 0)
			return result;
		int N = nums1.size(), M = nums2.size();
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