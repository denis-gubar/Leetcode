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
	vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
		vector<string> result;
		vector<vector<string>> P;
		for (string const& p : phrases)
			P.push_back(split(p, ' '));
		for(int i = 0; i < P.size(); ++i)
			for(int j = 0; j < P.size(); ++j)
				if (i != j && P[i].back() == P[j][0])
				{
					string current = phrases[i];
					for (int k = 1; k < P[j].size(); ++k)
						current += ' ', current += P[j][k];
					result.push_back(current);
				}
		sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};