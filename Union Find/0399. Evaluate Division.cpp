class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, int> keys;
		int N = 0;
		for(vector<string> const& eq : equations)
			if (eq[0] != eq[1])
				for (string const& v : eq)
				{
					auto it = keys.find(v);
					if (it == keys.end())
						keys[v] = N, ++N;
				}
		vector<vector<pair<int, double>>> connectivity(N);
		for(int i = 0; i < values.size(); ++i)
			if (equations[i][0] != equations[i][1])
			{
				int u = keys[equations[i][0]];
				int v = keys[equations[i][1]];
				connectivity[u].push_back({ v, values[i] });
				connectivity[v].push_back({ u, 1.0 / values[i] });
			}
		vector<double> result;
		for (int i = 0; i < queries.size(); ++i)
		{
			result.push_back(-1.0);
			if (keys.find(queries[i][0]) != keys.end() &&
				keys.find(queries[i][1]) != keys.end())
			{
				int u = keys[queries[i][0]];
				int v = keys[queries[i][1]];
				queue<pair<int, double>> Q;
				Q.push({ u, 1.0 });
				unordered_set<int> visited;
				visited.insert(u);
				while (!Q.empty())
				{
					auto [u, val] = Q.front(); Q.pop();
					if (u == v)
					{
						result.back() = val;
						break;
					}
					for(auto [x, y] : connectivity[u])
						if (visited.find(x) == visited.end())
						{
							Q.push({ x, val * y });
							visited.insert(x);
						}
				}
			}
		}
		return result;
	}
};