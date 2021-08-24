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
	int canBeTypedWords(string text, string brokenLetters) {
		vector<string> S = split(text, ' ');
		int result = 0;
		for (string const& x : S)
		{
			bool isOk = true;
			for (char c : brokenLetters)
				if (x.find(c) != string::npos)
					isOk = false;
			result += isOk;
		}
		return result;
	}
};