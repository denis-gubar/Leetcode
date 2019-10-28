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
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> result;
		vector<string> words = split(text);
		for (int i = 2; i < words.size(); ++i)
			if (words[i - 2] == first && words[i - 1] == second)
				result.push_back(words[i]);
		return result;
	}
};