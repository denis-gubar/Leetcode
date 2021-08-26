class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		vector<int> result;
		set<int> S;
		for (int i = 0; i < k; ++i)
			S.insert(i);
		int N = arrival.size();
		vector<int>	requestCount(N);
		priority_queue<pair<int, int>> Q;
		for (int i = 0; i < N; ++i)
		{
			while (!Q.empty() && -Q.top().first <= arrival[i])
			{
				int t = -Q.top().first;
				int server = Q.top().second; Q.pop();
				S.insert(server);
			}
			if (S.empty())
				continue;
			auto it = S.lower_bound(i % k);
			if (it == S.end())
				it = S.begin();
			int t = arrival[i] + load[i];
			int server = *it;
			Q.push({ -t, server });
			S.erase(it);
			++requestCount[server];
		}
		int best = *max_element(requestCount.begin(), requestCount.end());
		for (int i = 0; i < N; ++i)
			if (requestCount[i] == best)
				result.push_back(i);
		return result;
	}
};