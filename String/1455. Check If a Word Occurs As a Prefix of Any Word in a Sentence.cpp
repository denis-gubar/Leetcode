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
	int isPrefixOfWord(string sentence, string searchWord) {
		vector<string> S(split(sentence));
		int M = searchWord.size();
		for (int i = 0; i < S.size(); ++i)
			if (S[i].size() >= M && S[i].substr(0, M) == searchWord)
				return i + 1;
		return -1;
	}
};