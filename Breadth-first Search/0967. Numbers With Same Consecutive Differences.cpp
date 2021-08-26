class Solution {
public:
	void calc(vector<int>& result, int N, int K, int prefix, int prefixLength)
	{
		if (prefixLength == N)
		{
			result.push_back(prefix);
			return;
		}
		if (prefixLength == 0)
		{
			for (int i = 1; i < 10; ++i)
				calc(result, N, K, i, 1);
			if (N == 1)
				calc(result, N, K, 0, 1);
		}
		else
		{
			int lastDigit = prefix % 10;
			int a = (lastDigit + K) % 10;
			int b = (10 + lastDigit - K) % 10;
			if (abs(a - lastDigit) == K)
				calc(result, N, K, prefix * 10 + a, prefixLength + 1);
			if (a != b && abs(b - lastDigit) == K)
				calc(result, N, K, prefix * 10 + b, prefixLength + 1);
		}
	}
	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> result;
		calc(result, N, K, 0, 0);
		return result;
	}
};