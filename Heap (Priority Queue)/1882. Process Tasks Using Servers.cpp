class Solution {
public:
	vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		int N = servers.size(), M = tasks.size();
		vector<int> W(N);
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; ++i)
			A[i] = { servers[i], i };
		sort(A.begin(), A.end());
		for (int i = 0; i < N; ++i)
			W[i] = A[i].second;
		auto cmp = [](int a, int b)
		{
			return a > b;
		};
		priority_queue<int, vector<int>, decltype(cmp)> idle(cmp);
		for (int i = 0; i < N; ++i)
			idle.push(i);
		auto cmp2 = [](pair<long long, int> a, pair<long long, int> b)
		{
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
		};
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp2)> busy(cmp2);
		vector<int> result(M);
		long long T = -1;
		auto freeBusy = [&busy, &idle, &W](long long T)
		{
			while (!busy.empty() && busy.top().first <= T)
			{
				int serverId = busy.top().second;
				busy.pop();
				idle.push(serverId);
			}
		};
		int lastAdded = -1;
		auto add = [&idle, &busy, &lastAdded, &T, &tasks, &result, &W](int i)
		{
			while (!idle.empty() && lastAdded < i)
			{
				int serverId = idle.top();
				idle.pop();
				++lastAdded;
				busy.push({ T + tasks[lastAdded], serverId });
				result[lastAdded] = W[serverId];
			}
		};
		for (int i = 0; i < M; ++i)
		{
			++T;
			freeBusy(T);
			add(i);
		}
		while (lastAdded < M - 1)
		{
			T = busy.top().first;
			freeBusy(T);
			add(M - 1);
		}
		return result;
	}
};