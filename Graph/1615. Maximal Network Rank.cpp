class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		int result = 0;
		vector<bitset<100>> A(n);
		for (vector<int> const& road : roads)
		{
			A[road[0]][road[1]] = 1;
			A[road[1]][road[0]] = 1;
		}
		for (int a = 0; a < n; ++a)
			for (int b = a + 1; b < n; ++b)
			{
				int current = A[a].count() + A[b].count() - A[a][b];
				result = max<int>(result, current);
			}
		return result;
	}
};