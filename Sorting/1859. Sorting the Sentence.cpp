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
	string sortSentence(string s) {
		string result;
		vector<string> S(split(s));
		sort(S.begin(), S.end(), [](string const& a, string const& b)
			{
				return a.back() < b.back();
			});
		for (string& x : S)
		{
			x.pop_back();
			result += ' ';
			result += x;
		}
		return result.substr(1);
	}
};