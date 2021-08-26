class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, vector<int>> children;
		int N = pid.size();
		for (int i = 0; i < N; ++i)
			children[ppid[i]].push_back(pid[i]);
		vector<int> result;
		queue<int> Q;
		Q.push(kill);
		while (!Q.empty())
		{
			int id = Q.front(); Q.pop();
			result.push_back(id);
			for (int child : children[id])
				Q.push(child);
		}
		return result;
	}
};