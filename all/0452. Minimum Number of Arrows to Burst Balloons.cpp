class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty())
			return 0;
		int result = 0;
		sort(points.begin(), points.end(), [](vector<int> const& A, vector<int> const& B)
			{
				return A[1] < B[1];
			});
		long long prev = points[0][0] - 1LL;
		for(vector<int> const& point : points)
			if (prev < point[0])
			{
				prev = point[1];
				++result;
			}
		return result;
	}
};