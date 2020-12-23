class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> result;
		vector<bool> visited(n);
		vector<unordered_set<int>> connectivity(n);
		for (vector<int> const& e : edges)
		{
			connectivity[e[0]].insert(e[1]);
			connectivity[e[1]].insert(e[0]);
		}
		queue<int> Q;
		for (int i = 0; i < n; ++i)
			if (connectivity[i].size() <= 1)
				Q.push(i);
		int N = n;
		while (N > 2)
		{
			queue<int> NQ;
			while (!Q.empty())
			{
				--N;
				int V = Q.front(); Q.pop();
				visited[V] = true;
				for (int U : connectivity[V])
				{
					connectivity[U].erase(V);
					if (connectivity[U].size() == 1)
						NQ.push(U);
				}
				connectivity[V].clear();
			}
			Q = move(NQ);
		}
		for (int i = 0; i < n; ++i)
			if (!visited[i])
				result.push_back(i);
		return result;
	}
};