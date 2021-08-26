class Solution {
public:
	vector<string> split(const string& s, char delimeter = ' ')
	{
		vector<string> result;
		istringstream ss(s);
		for (string token; !ss.eof(); )
		{
			getline(ss, token, delimeter);
			result.push_back(token);
		}
		return result;
	}
	static inline void rtrim(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
			}).base(), s.end());
	}
	vector<string> printVertically(string s) {
		vector<string> S(split(s));
		size_t N = 0, M = S.size();
		for (string const& t : S)
			N = max(N, t.size());
		vector<string> result(N, string(M, ' '));
		for (int i = 0; i < S.size(); ++i)
			for (int j = 0; j < S[i].size(); ++j)
				result[j][i] = S[i][j];
		for (string& t : result)
			rtrim(t);
		return result;
	}
};