class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int>	result;
		vector<int>	degree(numCourses);
		set<pair<int, int>> S;
		vector<unordered_set<int>> inv(numCourses);
		for (vector<int> const& p : prerequisites)
		{
			++degree[p[0]];
			inv[p[1]].insert(p[0]);
		}
		for (int i = 0; i < numCourses; ++i)
			S.emplace(degree[i], i);
		while (!S.empty())
		{
			auto [d, V] = *S.begin();
            if (d)
                return {};
			result.push_back(V);
			S.erase(S.begin());
			for (int U : inv[V])
			{
				auto it = S.find({ degree[U], U });
                if (it == S.end())
                    continue;                    
				S.erase(it);
				--degree[U];
				S.emplace(degree[U], U);
			}
		}
		return result;
	}
};
