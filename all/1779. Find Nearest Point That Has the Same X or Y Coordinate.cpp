class Solution {
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int result = -1;
		for (int i = 0; i < points.size(); ++i)
			if (x == points[i][0] || y == points[i][1])
			{
				int d = abs(x - points[i][0]) + abs(y - points[i][1]);
				if (result == -1 || abs(x - points[result][0]) + abs(y - points[result][1]) > d)
					result = i;
			}
		return result;
	}
};