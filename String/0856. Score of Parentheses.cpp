class Solution {
public:
	int scoreOfParentheses(string S) {
		if (S.empty())
			return 0;
		if (S == "()")
			return 1;
		int N = S.size();
		int k = 1, pos = 1;
		while (k)
		{
			k += S[pos] == '(' ? 1 : -1;
			++pos;
		}
		if ( pos < N)
			return scoreOfParentheses(S.substr(0, pos)) + scoreOfParentheses(S.substr(pos));
		return 2 * scoreOfParentheses(S.substr(1, N - 2));
	}
};