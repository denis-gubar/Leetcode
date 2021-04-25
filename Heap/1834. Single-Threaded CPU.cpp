class Solution {
public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		vector<int> result;
		multiset<pair<long long, int>> S;
		int N = tasks.size();
		vector<int> A(N);
		iota(A.begin(), A.end(), 0);
		sort(A.begin(), A.end(), [&tasks](int a, int b)
			{
				if (tasks[a] != tasks[b])
					return tasks[a] < tasks[b];
				return a < b;
			});
		long long time = 0;
		int i = 0;
		while(i < N || !S.empty())
		{
			while (i < N && tasks[A[i]][0] <= time)
			{
				S.insert({ tasks[A[i]][1], A[i] });
				++i;
			}			
			if (S.empty())
				time = tasks[A[i]][0];
			else
			{
				time += S.begin()->first;
				result.push_back(S.begin()->second);
				S.erase(S.begin());
			}
		}
		return result;
	}
};