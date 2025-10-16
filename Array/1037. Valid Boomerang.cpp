class Solution {
public:
	double distance(vector<int>& A, vector<int>& B)
	{
		return sqrt(1.0 * (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]));
	}
	bool isBoomerang(vector<vector<int>>& points) {
		vector<double> M;
		M.push_back(distance(points[0], points[1]));
		M.push_back(distance(points[1], points[2]));
		M.push_back(distance(points[0], points[2]));
		sort(M.begin(), M.end());
		return M[0] > 0 && abs(M[2] - M[1] - M[0]) > 1e-7;
	}
};