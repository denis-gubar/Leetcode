class Solution {
public:
	int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
		int result = 0, delta = 0;
		int N = points.size();
		int const& X = location[0];
		int const& Y = location[1];
		double Z = 45.0 / atan(1.0);
		vector<double> A;
		for (int i = 0; i < N; ++i)
		{
			int const& x = points[i][0];
			int const& y = points[i][1];
			if (X == x && Y == y)
				++delta;
			else
			{
				A.push_back(atan2(0.0 + y - Y, 0.0 + x - X) * Z);
			}
		}
		sort(A.begin(), A.end());
		int k = A.size();
		for (int i = 0; i < k; ++i)
			A.push_back(360.0 + A[i]);
		queue<double> Q;
		for (double x : A)
		{
			Q.push(x);
			while (Q.front() + 1.0 * angle + 1e-15 < x)
				Q.pop();
			result = max<int>(result, Q.size());
		}
		return result + delta;
	}
};