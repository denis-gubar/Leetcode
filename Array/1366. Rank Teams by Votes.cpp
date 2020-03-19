class Solution {
public:
	string rankTeams(vector<string>& votes) {
		string result = votes[0];
		int N = votes.size(), M = votes[0].size();
		vector<vector<int>> count(128, vector<int>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				++count[votes[i][j]][j];
		sort(result.begin(), result.end(),
			[&count](char a, char b)
			{
				if (count[a] == count[b])
					return a < b;
				return count[a] > count[b];
			});
		return result;
	}
};