class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> F(10);
		F[0] = 1;
		for (int i = 1; i < 10; ++i)
			F[i] = F[i - 1] * i;
		--k;
		string result;
		for (int i = 1; i <= n; ++i)
			result += '0' + i;
		int pos = 0;
		while (k)
		{
			while (F[n - pos - 1] > k)
			{
				++pos;
				nth_element(result.begin() + pos, result.begin() + pos, result.end());
			}
			int delta = k / F[n - pos - 1];
			k %= F[n - pos - 1];
			nth_element(result.begin() + pos, result.begin() + pos + delta, result.end());
			swap(result[pos], result[pos + delta]);
		}
		sort(result.begin() + pos + 1, result.end());
		return result;
	}
};