class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int result = 0;
		int N = A.size();
		for (int x = 0, last = 0, pos = 2; pos <= N; ++pos)
		{
			if (pos < N && A[pos] - A[pos - 1] == A[last + 1] - A[last])
			{
				++x;
			}
			else
			{
				result += x * (x + 1) / 2;
				x = 0;
				last = pos - 1;
			}
		}
		return result;
	}
};