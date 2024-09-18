class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int result = 0;
        int N = points.size();
		vector<int> A(N);
		for (int i = 0; i < N; ++i)
			A[i] = points[i][0];
		sort(A.begin(), A.end());
		for (int i = 1; i < N; ++i)
			result = max(result, A[i] - A[i - 1]);
		return result;
	}
};