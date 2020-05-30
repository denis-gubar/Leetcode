class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<unordered_set<int>> connectivity(numCourses);
		vector<unordered_set<int>> inverse(numCourses);
		for (vector<int> const& prerequisite : prerequisites)
		{
			connectivity[prerequisite[0]].insert(prerequisite[1]);
			inverse[prerequisite[1]].insert(prerequisite[0]);
		}
		set<pair<int, int>> Q;
		for (int i = 0; i < numCourses; ++i)
			Q.emplace(connectivity[i].size(), i);
		while (!Q.empty())
		{
			pair<int, int> P = *Q.begin(); Q.erase(Q.begin());
			if (P.first > 0)
				return false;
			int const& V = P.second;
			for (int U : inverse[V])
			{
				pair<int, int> p{ connectivity[U].size(), U };
				Q.erase(p);
				connectivity[U].erase(V);
				--p.first;
				Q.insert(p);				
			}
			inverse[V].clear();
		}
		return true;
	}
};