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
	bool wordPattern(string pattern, string str) {
		vector<string> S({ split(str) });
		if (pattern.size() != S.size())
			return false;
		unordered_map<char, string> M;		
		for (int i = 0; i < S.size(); ++i)
		{
			auto it = M.find(pattern[i]);
			if (it == M.end())
				M[pattern[i]] = S[i];
			else if (it->second != S[i])
				return false;
		}
		unordered_map<string, char> I;
		for (int i = 0; i < S.size(); ++i)
		{
			auto it = I.find(S[i]);
			if (it == I.end())
				I[S[i]] = pattern[i];
			else if (it->second != pattern[i])
				return false;
		}
		return true;
	}
};