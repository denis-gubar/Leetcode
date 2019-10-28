class Solution {
public:
	static int F(string const& s)
	{
		char c = *min_element(s.begin(), s.end());
		return count(s.begin(), s.end(), c);
	}
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> result;
		vector<int> W(11);
		for (string const& word : words)
			++W[F(word)];
		for (string const& query : queries)
		{
			int f = F(query);
			result.push_back(0);
			for (int k = f + 1; k < 11; ++k)
				result.back() += W[k];
		}
		return result;
	}
};