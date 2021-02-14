class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int result = 0;
		int N = M.size();
		vector<bool> visited(N);
		for(int i = 0; i < N; ++i)
			if (!visited[i])
			{
				++result;
                visited[i] = true;
				queue<int> Q;
				Q.push(i);
				while (!Q.empty())
				{
					int v = Q.front(); Q.pop();
					for (int j = 0; j < N; ++j)
						if (!visited[j] && M[v][j])
						{
							visited[j] = true;
							Q.push(j);
						}
				}
			}
		return result;
	}
};