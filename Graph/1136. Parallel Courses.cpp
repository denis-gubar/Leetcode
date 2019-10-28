class Solution {
public:
	int minimumSemesters(int N, vector<vector<int>>& relations) {
		int result = 0;
		vector<set<int>> connectivity(N), prereq(N);
		for (vector<int> const& relation : relations)
		{
			connectivity[relation[0] - 1].insert(relation[1] - 1);
			prereq[relation[1] - 1].insert(relation[0] - 1);
		}
		set<pair<size_t, int>> S;
		for (int i = 0; i < N; ++i)
			S.insert({ prereq[i].size(), i });
		while (!S.empty())
		{
			if (S.begin()->first > 0)
				return -1;
			vector<int> Nodes;
			++result;
			while (!S.empty() && S.begin()->first == 0)
			{
				Nodes.push_back(S.begin()->second);
				S.erase(S.begin());
			}
			for (int v : Nodes)
				for (int u : connectivity[v])
				{
					auto it = S.find({ prereq[u].size(), u });
					prereq[u].erase(v);
					S.erase(it);
					S.insert({ prereq[u].size(), u });
				}
		}
		return result;
	}
};