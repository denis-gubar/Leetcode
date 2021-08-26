class Solution {
public:
	int climbStairs(int n) {
		vector<int> M(n + 2);
		M[0] = 1;
		for (int i = 0; i < n; ++i)
		{
			M[i + 1] += M[i];
			M[i + 2] += M[i];
		}
		return M[n];
	}
};