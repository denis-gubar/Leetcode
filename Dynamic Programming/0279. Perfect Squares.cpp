class Solution {
public:
	int numSquares(int n) {
		vector<int> A;
		for (int x = 1; x * x <= n; ++x)
			A.push_back(x * x);
		reverse(A.begin(), A.end());
		unordered_set<int> visited;
		visited.insert(0);
		queue<int> Q;
		Q.push(0); Q.push(0);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int step = Q.front(); Q.pop();
			if (x == n)
				return step;
			for (int dx : A)
			{
				int nx = x + dx;
				if (nx <= n && visited.find(nx) == visited.end())
				{
					visited.insert(nx);
					Q.push(nx); Q.push(step + 1);
				}
			}
		}
		return -1;
	}
};