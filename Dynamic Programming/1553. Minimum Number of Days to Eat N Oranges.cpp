class Solution {
public:
	int minDays(int n) {
		unordered_map<int, int> visited;
		queue<int> Q;
		Q.push(n);
		visited[n] = 0;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			if (x == 0)
				return visited[x];
			if (x % 3 == 0)
			{
				int nx = x / 3;
				if (visited.find(nx) == visited.end() || visited[nx] > visited[x] + 1)
				{
					visited[nx] = visited[x] + 1;
					Q.push(nx);
				}
			}
			if (x % 2 == 0)
			{
				int nx = x / 2;
				if (visited.find(nx) == visited.end() || visited[nx] > visited[x] + 1)
				{
					visited[nx] = visited[x] + 1;
					Q.push(nx);
				}
			}
			{
				int nx = x - 1;
				if (visited.find(nx) == visited.end() || visited[nx] > visited[x] + 1)
				{
					visited[nx] = visited[x] + 1;
					Q.push(nx);
				}
			}
		}
		return -1;
	}
};