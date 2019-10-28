class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		vector<vector<int>> state(grid);
		int result = 0;
		vector<int> dx{ 0, -1, 0, 1 };
		vector<int> dy{ -1, 0, 1, 0 };
		while (true)
		{
			int freshCount = 0;
			for (auto& row : state)
				for (int x : row)
					if (x == 1)
						++freshCount;
			if (freshCount == 0)
				return result;
			++result;
			vector<vector<int>> newState(state);
			for(int i = 0; i < state.size(); ++i)
				for (int j = 0; j < state[0].size(); ++j)
					if (state[i][j] == 2)
						for (int z = 0; z < 4; ++z)
						{
							int nx = i + dx[z];
							int ny = j + dy[z];
							if (nx >= 0 && nx < state.size() && ny >= 0 && ny < state[0].size() && newState[nx][ny] == 1)
								newState[nx][ny] = 2;
						}
   			if (state == newState)
				break;
			state.swap(newState);
		}
		return -1;
	}
};