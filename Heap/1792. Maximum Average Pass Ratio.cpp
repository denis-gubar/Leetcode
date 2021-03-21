class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		int N = classes.size();
		auto delta = [&classes](int x)
		{
			double p = classes[x][0];
			double q = classes[x][1];
			return (p + 1.0) / (q + 1.0) - p / q;
		};
		auto cmp = [&delta](int a, int b)
		{
			return delta(a) < delta(b);
		};
		priority_queue<int, vector<int>, decltype(cmp)> PQ(cmp);
		for (int i = 0; i < N; ++i)
			PQ.push(i);
		for (int k = 0; k < extraStudents; ++k)
		{
			int x = PQ.top(); PQ.pop();
			++classes[x][0];
			++classes[x][1];
			PQ.push(x);
		}
		double result = 0;
		for (int i = 0; i < N; ++i)
		{
			double p = classes[i][0];
			double q = classes[i][1];
			q *= N;
			result += p / q;
		}
		return result;
	}
};