class Solution {
public:
	int maxNumberOfBalloons(string text) {
		string s("balloon");
		map<char, int> M, N;
		for (char c : s)
			++M[c];
		for (char c : text)
			++N[c];
		int result = N['b'];
		for (char c : s)
			result = min(result, N[c] / M[c]);
		return result;
	}
};