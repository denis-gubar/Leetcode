class Solution {
public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		long long result = 0;
		int N = matrix.size(), M = matrix[0].size();
		int A = abs(matrix[0][0]);
		long long total = 0;
		int negativeCount = 0;
		for (vector<int> const& row : matrix)
		{
			A = min(A, abs(*min_element(row.begin(), row.end(), [](int a, int b)
				{
					return abs(a) < abs(b);
				})));			
			for (int x : row)
			{
				negativeCount += x < 0;
				total += abs(x);
			}
		}
		if (negativeCount % 2 == 1)
			total -= 2 * A;
		return total;
	}
};