class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		vector<int> visited(10000);
		for (const string& deadend : deadends)
			visited[atoi(deadend.c_str())] = 1;
		if (visited[0])
			return -1;
		visited[0] = 1;
		queue<int> Q;
		Q.push(0); Q.push(0);
		while (!Q.empty())
		{
			int state = Q.front(); Q.pop();
			int step = Q.front(); Q.pop();
			string s(to_string(10000 + state).substr(1));
			if (s == target)
				return step;
			for(int i = 0; i < 4; ++i)
				for (int dx = -1; dx <= 1; dx += 2)
				{
					string ns(s);
					ns[i] = ((ns[i] - '0') + dx + 10) % 10 + '0';
					int newState = atoi(ns.c_str());
					if (!visited[newState])
					{
						visited[newState] = 1;
						Q.push(newState); Q.push(step + 1);
					}
				}
		}
		return -1;
	}
};