class Solution {
public:
	int MIN = numeric_limits<int>::min();
	int calc(vector<vector<int>> const& connectivity, vector<int> const& value, vector<int>& F, int v)
	{
		if (F[v] == MIN)
		{
			F[v] = value[v];
			for (int u : connectivity[v])
				F[v] += calc(connectivity, value, F, u);
		}
		return F[v];
	}
	int size(vector<vector<int>> const& connectivity, vector<int>& S, int v)
	{
		if (S[v] == MIN)
		{
			S[v] = 1;
			for (int u : connectivity[v])
				S[v] += size(connectivity, S, u);
		}
		return S[v];
	}
	int traverse(vector<vector<int>> const& connectivity, vector<int> const& F, vector<int> const& S)
	{
		int result = 0;
		if (F[0] == 0)
			return S[0];
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			for (int u : connectivity[v])
				if (F[u] == 0)
					result += S[u];
				else
					Q.push(u);
		}
		return result;
	}
	int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
		vector<vector<int>> connectivity(nodes);
		for(int i = 0; i < nodes; ++i)
			if (parent[i] != -1)
				connectivity[parent[i]].push_back(i);
		vector<int> F(nodes, MIN);
		vector<int> S(nodes, MIN);
		for (int i = 0; i < nodes; ++i)
		{
			calc(connectivity, value, F, i);
			size(connectivity, S, i);
		}
		return nodes - traverse(connectivity, F, S);
	}
};