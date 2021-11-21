class Solution {
public:
	int calc(int V)
	{
		if (T[V] == 0)
		{
			int result = 0;
			for (int U : prerequisites[V])
				result = max(result, calc(U));
			T[V] = time[V - 1] + result;
		}
		return T[V];
	}
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		this->time = time;
		T = vector<int>(n + 1);
		prerequisites = vector<vector<int>>(n + 1);
		for (vector<int> const& r : relations)
		{
			int const& prevCourse = r[0];
			int const& nextCourse = r[1];
			prerequisites[nextCourse].push_back(prevCourse);
		}
		int result = 0;
		for (int V = 1; V <= n; ++V)
			result = max(result, calc(V));
		return result;
	}
	vector<int> time;
	vector<int> T;
	vector<vector<int>> prerequisites;
};