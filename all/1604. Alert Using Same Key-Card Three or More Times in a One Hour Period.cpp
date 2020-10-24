class Solution {
public:
	int parse(string const& s)
	{
		int result = 0;
		result += (s[0] - '0') * 600;
		result += (s[1] - '0') * 60;
		result += (s[3] - '0') * 10;
		result += (s[4] - '0');
		return result;
	}
	vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
		set<string> result;
		unordered_map<string, int> M;
		queue<pair<string, int>> Q;
		vector<pair<int, string>> P;
		for (int i = 0; i < keyName.size(); ++i)
			P.push_back({ parse(keyTime[i]), keyName[i] });
		sort(P.begin(), P.end());
		for (int i = 0; i < keyName.size(); ++i)
		{
			int t = P[i].first;
			string const& s = P[i].second;
			++M[s];
			Q.push({ s, t });
			while (t - Q.front().second > 60)
			{
				--M[Q.front().first];
				Q.pop();
			}
			if (M[s] == 3)
				result.insert(s);
		}
		return vector<string>(result.begin(), result.end());
	}
};