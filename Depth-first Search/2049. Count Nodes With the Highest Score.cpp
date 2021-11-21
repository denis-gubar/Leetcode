class Solution {
public:
	int dfs(vector<vector<int>> const& children, vector<int>& sizes, int V)
	{		
		int result = 1;
		for (int U : children[V])
			result += dfs(children, sizes, U);
		return sizes[V] = result;
	}
	int countHighestScoreNodes(vector<int>& parents) {
		int N = parents.size();
		vector<vector<int>> children(N);
		for (int i = 1; i < N; ++i)
			children[parents[i]].push_back(i);
		vector<int> sizes(N);
		dfs(children, sizes, 0);
		map<long long, int> scores;
		for (int V = 0; V < N; ++V)
		{
			long long score = max(1, N - sizes[V]);
			for (int U : children[V])
				score *= sizes[U];
			++scores[score];
		}
		return scores.rbegin()->second;
	}
};