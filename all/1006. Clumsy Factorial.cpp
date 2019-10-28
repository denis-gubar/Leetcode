class Solution {
public:
	int clumsy(int N) {
		if (N == 1)
			return 1;
		if (N == 2)
			return 2;
		if (N == 3)
			return 6;
		int result = N * (N - 1) / (N - 2) + (N - 3);
		N -= 4;
		while (N >= 4)
		{
			result -= N * (N - 1) / (N - 2);
			result += (N - 3);
			N -= 4;
		}
		if (N == 3)
			result -= 6;
		else
			result -= N;
		return result;
	}
};