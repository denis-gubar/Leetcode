class Solution {
public:
	int distinctEchoSubstrings(string text) {
		int N = text.length();
		unordered_set<string> S;
		for (int i = 0; i < N; ++i)
			for (int j = i + 1, length = j - i; j + length <= N; ++j, ++length)
				if (equal(text.begin() + i, text.begin() + (i + length), text.begin() + j, text.begin() + (j + length)))
					S.insert(text.substr(i, length));
		return S.size();
	}
};