class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		int result = 0;
		vector<vector<int>> connectivity(n);
		for (vector<int> const& conn : connections)
		{
			connectivity[conn[0]].push_back(conn[1]);
			connectivity[conn[1]].push_back(n + conn[0]);
		}
		int V = 0;
		queue<int> Q;
		Q.push(V); Q.push(-1);
		while (!Q.empty())
		{
			V = Q.front(); Q.pop();
			int from = Q.front(); Q.pop();
			for (int NU : connectivity[V])
			{
				int U = NU % n;
				if (U == from)
					continue;
				if (NU == U)
					++result;
				Q.push(U); Q.push(V);
			}
		}
		return result;
	}
};