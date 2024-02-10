class Solution {
public:
	vector<int> z_function(string const& s) {
		int N = s.size();
		vector<int> result(N);
		for (int i = 1, l = 0, r = 0; i < N; ++i) {
			if (i <= r)
				result[i] = min(r - i + 1, result[i - l]);
			while (i + result[i] < N && s[result[i]] == s[i + result[i]])
				++result[i];
			if (i + result[i] - 1 > r)
				l = i, r = i + result[i] - 1;
		}
		return result;
	}
    int minimumTimeToInitialState(string word, int K) {
        int N = word.size();
		if (N == 1 || N == K)
			return 1;
		vector<int> Z = z_function(word);
		int result = 0;
		for (int i = K; i < N; i += K)
		{
			if (i % K == 0)
				++result;
			if (Z[i] > 0)
			{
				if (i + Z[i] >= N)
					return result;
			}
		}
		return (N + K - 1) / K;
    }
};
