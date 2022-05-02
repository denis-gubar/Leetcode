class Solution {
public:
	int countWords(vector<string>& words1, vector<string>& words2) {
		int result = 0;
		unordered_map<string, int> M1, M2;
		for (string const& s : words1)
			++M1[s];
		for (string const& s : words2)
			++M2[s];
		for (auto [key, value] : M1)
			if (value == 1 && M2[key] == 1)
				++result;
		return result;
	}
};