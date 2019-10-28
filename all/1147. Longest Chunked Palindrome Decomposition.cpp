class Solution {
public:
	int longestDecomposition(string const& text, int start = 0) {
		int result = 0;
		int n = text.size() - 2 * start;
		if (n) result = 1;
		for (int length = 1; length <= n / 2; ++length)
			if (text.substr(start, length) == text.substr(start + n - length, length))
				result = max(result, 2 + longestDecomposition(text, start + length));
		return result;
	}
};