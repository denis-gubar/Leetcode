class Solution {
public:
	double calc(double x, double y, vector<vector<int>> const& positions)
	{
		double result = 0.0;
		for (vector<int> const& p : positions)
			result += sqrt((x - p[0])* (x - p[0]) + (y - p[1]) * (y - p[1]));
		return result;
	}
	double getMinDistSum(vector<vector<int>>& positions) {
		double result = 0.0;
		double x = 50.0, y = 50.0;
		for (double length = 50.0; length > 1e-10; length /= 2)
		{
			double nx = x, ny = y;
			double nd = calc(nx, ny, positions);
			for(int dx = -5; dx <= 5; ++dx)
				for (int dy = -5; dy <= 5; ++dy)
				{
					double d = calc(x + 0.1 * dx * length, y + 0.1 * dy * length, positions);
					if (d < nd)
					{
						nd = d, nx = x + 0.1 * dx * length, ny = y + 0.1 * dy * length;
					}
				}
			x = nx, y = ny;
		}
		result = calc(x, y, positions);
		return result;
	}
};