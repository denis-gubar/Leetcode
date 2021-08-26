class Solution {
public:
	int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		int result = 0;
		map<string, int> M;
		string prefix(s.substr(0, minSize - 1));
		vector<int> counts(26);
		int distinctCount = 0;
		for (int i = 0; i + 1 < minSize; ++i)
			if (++counts[s[i] - 'a'] == 1)
				++distinctCount;
		for (int start = 0; start + minSize <= s.size(); ++start)
		{
			if (start)
				if (--counts[s[start - 1] - 'a'] == 0)
					--distinctCount;
			if (++counts[s[start + minSize - 1] - 'a'] == 1)
				++distinctCount;
			if (distinctCount <= maxLetters)
				++M[s.substr(start, minSize)];
		}
		for (auto m : M)
			result = max(result, m.second);
		return result;
	}
};