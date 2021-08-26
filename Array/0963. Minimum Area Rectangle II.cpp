class Solution {
public:
	double square(const vector<int>& A, const vector<int>& B, const vector<int>& C)
	{
		double c = sqrt((A[0] - B[0])*(A[0] - B[0]) + (A[1] - B[1])*(A[1] - B[1]));
		double b = sqrt((B[0] - C[0])*(B[0] - C[0]) + (B[1] - C[1])*(B[1] - C[1]));
		double a = sqrt((C[0] - A[0])*(C[0] - A[0]) + (C[1] - A[1])*(C[1] - A[1]));
		double p = (a + b + c) * 0.5;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	bool check(const vector<int>& A, const vector<int>& B, const vector<int>& C)
	{
		int c = (A[0] - B[0])*(A[0] - B[0]) + (A[1] - B[1])*(A[1] - B[1]);
		int b = (B[0] - C[0])*(B[0] - C[0]) + (B[1] - C[1])*(B[1] - C[1]);
		int a = (C[0] - A[0])*(C[0] - A[0]) + (C[1] - A[1])*(C[1] - A[1]);
		vector<int> X{ a, b, c };
		sort(X.begin(), X.end());
		return X[0] + X[1] == X[2];
	}
	double minAreaFreeRect(vector<vector<int>>& points) {
		double result = (1 << 30) + 100;
		int N = points.size();
		for(int a = 0; a < N; ++a)
			for(int b = a + 1; b < N; ++b)
				for(int c = b + 1; c < N; ++c)
					if (check(points[a], points[b], points[c]))
						for (int d = c + 1; d < N; ++d)
						{
							if (check(points[a], points[b], points[d]) &&
								check(points[a], points[c], points[d]) &&
								check(points[b], points[c], points[d]))
							{
								result = min(result, 2.0 * square(points[a], points[b], points[c]));
							}
						}
		if (result > (1 << 30))
			result = 0;
		return result;
	}
};