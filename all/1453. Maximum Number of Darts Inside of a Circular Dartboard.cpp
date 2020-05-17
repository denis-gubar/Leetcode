class Solution {
public:
	int calc(double px, double qx, double py, double qy, double r2, vector<vector<int>> const& points)
	{
		int result = 0;
		px *= qy;
		py *= qx;
		r2 *= qx * qy * qx * qy;
		for (vector<int> const& point : points)
		{
			double x = point[0], y = point[1];
			x *= qx * qy;
			y *= qx * qy;            
			result += 1.0 * (x - px) * (x - px) + (y - py) * (y - py) <= r2;
		}
		return result;
	}
	long long  gcd(long long  a, long long  b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	int numPoints(vector<vector<int>>& points, int r) {
		int result = 1;
		r *= 2;
		int r2 = r * r;
		for (vector<int>& point : points)
			for (int& p : point)
				p *= 2;
		set<vector<long long>> S;
		int N = points.size();
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (i != j)
				{
					long long x = (points[i][0] + points[j][0]) / 2;
					long long y = (points[i][1] + points[j][1]) / 2;
					S.insert({ x, 1LL, y, 1LL });
				}
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				for (int k = j + 1; k < N; ++k)
				{
					long long x12 = points[i][0] - points[j][0];
					long long x23 = points[j][0] - points[k][0];
					long long x31 = points[k][0] - points[i][0];
					long long y12 = points[i][1] - points[j][1];
					long long y23 = points[j][1] - points[k][1];
					long long y31 = points[k][1] - points[i][1];
					long long A = x12 * x12 + y12 * y12;
					long long B = x23 * x23 + y23 * y23;
					long long C = x31 * x31 + y31 * y31;
					vector<long long> T{ A, B, C };
					sort(T.begin(), T.end());
					if (T[2] >= T[0] + T[1])
						continue;
					long long z1 = points[i][0] * points[i][0] + points[i][1] * points[i][1];
					long long z2 = points[j][0] * points[j][0] + points[j][1] * points[j][1];
					long long z3 = points[k][0] * points[k][0] + points[k][1] * points[k][1];
					long long zx = y12 * z3 + y23 * z1 + y31 * z2;
					long long zy = x12 * z3 + x23 * z1 + x31 * z2;
					long long z = x12 * y31 - y12 * x31;
					long long K = gcd(abs(zx), abs(2 * z));
					long long px = K ? -zx / K : -zx;
					long long qx = K ? 2 * z / K : 2 * z;
					if (px < 0 && qx > 0 || px > 0 && qx < 0)
						px = -abs(px), qx = abs(qx);
					else
						px = abs(px), qx = abs(qx);
					K = gcd(abs(zy), abs(2 * z));
					long long py = K ? zy / K : zy;
					long long qy = K ? 2 * z / K : 2 * z;
					if (py < 0 && qy > 0 || py > 0 && qy < 0)
						py = -abs(py), qy = abs(qy);
					else
						py = abs(py), qy = abs(qy);
					S.insert({ px, qx, py, qy });
				}
		for (vector<long long> p : S)
			result = max(result, calc(p[0], p[1], p[2], p[3], r2, points));
		return result;
	}
};