class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		int INF = 1'000'000'000, result = INF;
		set<vector<int>> S;
		for (vector<int> const& point : points)
			S.emplace(point);
		int N = points.size();
		for (int i = 0; i < N; ++i)
			for (int j = 1; j < N; ++j)
				if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
				{
					int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
					if (area < result && S.find({ points[i][0], points[j][1] }) != S.end() &&
						S.find({ points[j][0], points[i][1] }) != S.end())
						result = area;
				}
		if (result == INF)
			result = 0;
		return result;
	}
};