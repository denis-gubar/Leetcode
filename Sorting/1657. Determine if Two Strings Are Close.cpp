class Solution {
public:
	vector<int> calc(string const& s)
	{
		vector<int> A(26);
		for (char c : s)
			++A[c - 'a'];
		sort(A.begin(), A.end());
		return A;
	}
	string calc2(string s)
	{
		sort(s.begin(), s.end());
		s.resize(unique(s.begin(), s.end()) - s.begin());
		return s;
	}
	bool closeStrings(string word1, string word2) {
		return calc(word1) == calc(word2) and calc2(word1) == calc2(word2);
	}
};