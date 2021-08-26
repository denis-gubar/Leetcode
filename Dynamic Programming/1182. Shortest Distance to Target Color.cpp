class Solution {
public:
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		vector<int> result;
		int N = colors.size();
		vector<vector<int>> distances(N, vector<int>(4, N));
		for (int c = 1; c < 4; ++c)
		{
			queue<int> q;
			for (int i = 0; i < N; ++i)
				if (colors[i] == c)
					q.push(i), distances[i][c] = 0;
			while (!q.empty())
			{
				int index = q.front(); q.pop();
				for (int dx = -1; dx <= 1; dx += 2)
				{
					int nIndex = dx + index;
					if (nIndex >= 0 && nIndex < N && distances[nIndex][c] > distances[index][c] + 1)
						distances[nIndex][c] = distances[index][c] + 1, q.push(nIndex);
				}
			}
		}
		for (vector<int> const& query : queries)
		{
			int current = distances[query[0]][query[1]];
			if (current == N)
				current = -1;
			result.push_back(current);
		}
		return result;
	}
};