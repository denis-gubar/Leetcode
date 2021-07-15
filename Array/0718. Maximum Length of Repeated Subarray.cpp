class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int result = 0;
		int N = nums1.size(), M = nums2.size();
		vector<vector<int>> F(2, vector<int>(M + 1));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				result = max(result, F[(i + 1) % 2][j + 1] = (nums1[i] == nums2[j]) ? F[i % 2][j] + 1 : 0);
		return result;
	}
};