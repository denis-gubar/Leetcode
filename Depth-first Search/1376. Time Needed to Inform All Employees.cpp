class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vector<int> visited(n);
		vector<vector<int>> subordinates(n);
		for (int i = 0; i < n; ++i)
			if (manager[i] != -1)
				subordinates[manager[i]].push_back(i);
		int count = 0;
		queue<int> Q;
		Q.push(headID);
		visited[headID] = 0;
		while (!Q.empty())
		{
			int head = Q.front(); Q.pop();
			for (int s : subordinates[head])
			{
				visited[s] = visited[head] + informTime[head];
				Q.push(s);
			}
		}
		return *max_element(visited.begin(), visited.end());
	}
};