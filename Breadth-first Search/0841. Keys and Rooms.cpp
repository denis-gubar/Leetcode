class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int N = rooms.size();
		vector<int> visited(N);
		visited[0] = 1;
		int V = 1;
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			for(int u: rooms[v])
				if (!visited[u])
				{
					++V;
					visited[u] = 1;
					Q.push(u);
				}
		}
		return V == N;
	}
};