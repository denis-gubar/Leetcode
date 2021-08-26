class Solution {
public:
	vector<int> calc(const string& word)
	{
		vector<int> result;
		map<char, int> M;
		int k = 0;
		for (char c : word)
		{
			if (M.find(c) == M.end())
			{
				M[c] = k;
				++k;
			}
			result.push_back(M[c]);
		}
		return result;
	}
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> result;
		vector<int> patternHash = calc(pattern);
		for (const string& word : words)
			if (calc(word) == patternHash)
				result.push_back(word);
		return result;
	}
};