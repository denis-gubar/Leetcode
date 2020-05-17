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
	string arrangeWords(string text) {
		vector<string> S = split(text);
		stable_sort(S.begin(), S.end(), [](string const& a, string const& b)
			{
				return a.size() < b.size();
			});
		string result;
		for (string const& s : S)
			result += ' ', result += s;
		result = result.substr(1);
		for (char& c : result)
			c = tolower(c);
		result[0] = toupper(result[0]);
		return result;
	}
};