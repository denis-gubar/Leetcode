class Solution {
public:
	bool areOccurrencesEqual(string s) {
		unordered_map<char, int> M;
		for (char c : s)
			++M[c];
		for (auto p : M)
			if (p.second != M.begin()->second)
				return false;
		return true;
	}
};