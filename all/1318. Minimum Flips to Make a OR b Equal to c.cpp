class Solution {
public:
	vector<int> convert(int x)
	{
		vector<int> result;
		for (int k = 0; k < 30; ++k)
		{
			result.push_back(x % 2);
			x /= 2;
		}
		return result;
	}
	int minFlips(int a, int b, int c) {
		int result = 0;
		vector<int> A(convert(a));
		vector<int> B(convert(b));
		vector<int> C(convert(c));
		for (int k = 0; k < 30; ++k)
		{
			if (C[k] == 0)
				result += A[k] + B[k];
			else
				result += 1 - max(A[k], B[k]);
		}
		return result;
	}
};