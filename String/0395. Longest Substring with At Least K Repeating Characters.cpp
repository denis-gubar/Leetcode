class Solution {
public:
	int calc(vector<vector<int>> const& count, string const& s, int start, int length, int k)
	{
		if (length < k)
			return 0;
		vector<bool> bad(26);
		bool hasBad = false;
		for (int c = 0; c < 26; ++c)
		{
			int x = count[c][start + length] - count[c][start];
			if (x > 0 && x < k)
				hasBad = bad[c] = true;
		}
		if (!hasBad)
			return length;
		int result = 0;
        int end = start + length;
		for (int pos = start; pos < end; ++pos)
		{
			if (bad[s[pos] - 'a'])
			{
				result = max(result, calc(count, s, start, pos - start, k));
				start = pos + 1;
			}
		}
        result = max(result, calc(count, s, start, end - start, k));
		return result;

	}
	int longestSubstring(string s, int k) {
		int N = s.size();
		vector<bool> gaps(N);
		vector<vector<int>> count(26, vector<int>(N + 1));
		for (int i = 0; i < N; ++i)
		{
			for (int c = 0; c < 26; ++c)
				count[c][i + 1] += count[c][i];
			++count[s[i] - 'a'][i + 1];
		}
		return calc(count, s, 0, N, k);
	}
};