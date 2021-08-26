class Solution {
public:
	int minFlipsMonoIncr(string S) {
		int N = S.size();
		vector<int> zeroesAfter(N), onesBefore(N);
		for (int i = N - 1; i >= 0; --i)
			zeroesAfter[i] += ((i == N - 1) ? 0 : zeroesAfter[i + 1]) + (S[i] == '0');
		for (int i = 0; i < N; ++i)
			onesBefore[i] += ((i == 0) ? 0 : onesBefore[i - 1]) + (S[i] == '1');
		int result = min(zeroesAfter[0], onesBefore[N - 1]);
		for (int pos = 1; pos < N; ++pos)
			result = min(result, onesBefore[pos - 1] + zeroesAfter[pos]);
		return result;
	}
};