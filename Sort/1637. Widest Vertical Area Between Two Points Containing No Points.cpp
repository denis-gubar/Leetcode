class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int result = 0;
		vector<int> A;
		for (int i = 0; i < points.size(); ++i)
			A.push_back(points[i][0]);
		sort(A.begin(), A.end());
		for (int i = 1; i < A.size(); ++i)
			result = max(result, A[i] - A[i - 1]);
		return result;
	}
};