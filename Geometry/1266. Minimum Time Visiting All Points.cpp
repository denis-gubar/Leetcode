class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int result = 0;
		int x = points[0][0], y = points[0][1];
		for (vector<int> const& point : points)
		{
			int px = point[0], py = point[1];
			result += max(abs(px - x), abs(py - y));
			x = px, y = py;
		}
		return result;
	}
};