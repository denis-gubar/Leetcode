class Solution {
public:
	bool check(set<vector<int>>& blocked, vector<int>& source, vector<int>& target)
	{
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		set<vector<int>> visited;
		queue<vector<int>> q;
		q.push(source);
		visited.insert(source);
		while (!q.empty())
		{
			vector<int> x = q.front(); q.pop();
			if (source == target)
				return true;
			if (visited.size() == 11'000)
				return true;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x[0] + dx[z];
				int ny = x[1] + dy[z];
				if (nx >= 0 && ny >= 0 && visited.find({ nx, ny }) == visited.end() && blocked.find({ nx, ny }) == blocked.end())
				{
					visited.insert({ nx, ny });
					q.push({ nx, ny });
				}
			}
		}
		return false;
	}
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		set<vector<int>> S(blocked.begin(), blocked.end());
		if (S.find(source) != S.end() || S.find(target) != S.end())
			return false;
		return check(S, source, target) && check(S, target, source);
	}
};