class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		int result = 1000000007;
		set<vector<int>> S;
		for (const vector<int>& point : points)
			S.insert(point);
		for (int i = 0; i < points.size(); ++i)
		{
			int A = points[i][0], B = points[i][1];
			for (int j = i + 1; j < points.size(); ++j)
			{
				int C = points[j][0], D = points[j][1];
				if (A != C && B != D &&
					S.find({ A, D }) != S.end() &&
					S.find({ C, B }) != S.end())
					result = min(result, abs(A - C) * abs(B - D));
			}
		}
		if (result == 1000000007)
			result = 0;
		return result;
	}
};