class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int result = 0;
		int x = 0, y = 0, d = 0;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		set<pair<int, int>> S;
		for (int i = 0; i < obstacles.size(); ++i)
			S.insert({ obstacles[i][0], obstacles[i][1] });
		for (int i = 0; i < commands.size(); ++i)
		{
			if (commands[i] == -2)
				d = (d + 3) % 4;
			if (commands[i] == -1)
				d = (d + 1) % 4;
			if (commands[i] > 0)
			{
				for (int j = 0; j < commands[i]; ++j)
				{
					int nx = x + dx[d], ny = y + dy[d];
					if (S.find({ nx, ny }) != S.end())
						break;
					x = nx, y = ny;
					result = max(result, x * x + y * y);
				}
			}
		}
		return result;
	}
};