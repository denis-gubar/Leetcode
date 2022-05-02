class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> result;
		vector<string> S;
		string buffer;
		for (char c : text)
			if (c == ' ')
			{
				S.push_back(buffer);
				buffer.clear();
			}
			else
			{
				buffer += c;
			}
		S.push_back(buffer);
		for (int i = 0; i + 2 < S.size(); ++i)
			if (S[i] == first && S[i + 1] == second)
				result.push_back(S[i + 2]);
		return result;
	}
};