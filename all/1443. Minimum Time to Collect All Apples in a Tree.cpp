class Solution {
public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		vector<int> appleCount(n);
		unordered_set<int> visited;
		for (int i = 0; i < n; ++i)
			visited.insert(i);
		vector<unordered_set<int>> connectivity(n);
		for (auto const& edge : edges)
		{
			int const& u = edge[0];
			int const& v = edge[1];
			connectivity[u].insert(v);
			connectivity[v].insert(u);
		}
		while (!visited.empty())
		{
			auto it = visited.begin();
			while (it != visited.end())
			{
				int v = *it;
                if (v == 0 && visited.size() > 1)
                {
                    ++it;
                    if (it == visited.end())
                        break;
                    v = *it;
                }
				if (connectivity[v].size() == 1)
				{
					it = visited.erase(it);
					int u = *connectivity[v].begin();
					connectivity[v].clear();
					connectivity[u].erase(connectivity[u].find(v));
                    if (connectivity[u].empty() && visited.find(u) != visited.end())
                    {
                        if (it == visited.find(u))
                            it = visited.erase(it);
                        else
                            visited.erase(u);
                    }
					if (appleCount[v] == 0)
						appleCount[u] += 2 * hasApple[v];
					else
						appleCount[u] += appleCount[v] + 2;
				}
				else
					++it;

			}
		}
		return appleCount[0];
	}
};