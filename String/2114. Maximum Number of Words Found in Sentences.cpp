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
	int mostWordsFound(vector<string>& sentences) {
		int result = 0;
		for (string const& s : sentences)
			result = max<int>(result, split(s).size());
		return result;
	}
};