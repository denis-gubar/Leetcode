class Solution {
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
public:
	vector<string> uncommonFromSentences(string A, string B) {
		vector<string> result;
		vector<string> a = split(A);
		vector<string> b = split(B);
		map<string, int> M;
		for (const string& s : a)
			++M[s];
		for (const string& s : b)
			++M[s];
		for (const auto p : M)
			if (p.second == 1)
				result.push_back(p.first);
		return result;
	}
};