class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		int N = wage.size();
		vector<pair<int, int>> workers(N);
		for (int i = 0; i < N; ++i)
			workers[i] = { quality[i], wage[i] };
		sort(workers.begin(), workers.end(), [](pair<int, int> a, pair<int, int> b)
			{
				return a.second * b.first < b.second * a.first;
			});
		double result = numeric_limits<double>::max();
		int sum = 0;
		priority_queue<int> Q;
		for (int i = 0; i < N; ++i)
		{
			Q.push(workers[i].first);
			sum += workers[i].first;
			if (Q.size() > K)
			{
				sum -= Q.top(); Q.pop();
			}
			if (Q.size() == K)
				result = min(result, 1.0 * workers[i].second / workers[i].first * sum);
		}
		return result;
	}
};