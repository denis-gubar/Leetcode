class Solution {
public:
	void calc(string& x, int num, int N, int k)
	{
		if (N == 1) return;
		if (num >= N / 2)
		{
			x[k - 1] = '0';
			num -= N / 2;
		}
		calc(x, num, N / 2, k - 1);
	}
	string encode(int num) {
		if (num == 0) return "";
		int N = 2;
		int x = 2;
		int k = 1;
		while (x < num)
		{
			N *= 2; x += N; ++k;
		}
		string result(k, '1');
		calc(result, x - num, N, k);
		reverse(result.begin(), result.end());
		return result;
	}
};