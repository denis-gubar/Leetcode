class Solution {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<int> visited(N + 1, -1);
		vector<vector<int>> connectivity(N + 1);
		for (vector<int> const& dislike : dislikes)
		{
			connectivity[dislike[0]].push_back(dislike[1]);
			connectivity[dislike[1]].push_back(dislike[0]);
		}
		for(int i = 1; i <= N; ++i)
			if (visited[i] == -1)
			{
				int start = i;
				int color = 0;
				visited[i] = color;
				queue<int> Q;
				Q.push(start); Q.push(color);
				while (!Q.empty())
				{
					int V = Q.front(); Q.pop();
					color = Q.front(); Q.pop();
					for (int U : connectivity[V])
						if (visited[U] == -1)
						{
							visited[U] = 1 - color;
							Q.push(U); Q.push(1 - color);
						}
						else if (visited[U] == color)
							return false;

				}
			}
		return true;
	}
};