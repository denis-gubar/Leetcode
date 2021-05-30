class Solution {
public:
	vector<int> getBiggestThree(vector<vector<int>>& grid) {
		vector<int> result;
		int N = grid.size(), M = grid[0].size();
		set<int> S;
		auto add = [&S](int x)
		{
			S.insert(x);
			if (S.size() == 4)
				S.erase(S.begin());
		};
		unordered_map<int, vector<int>> M1, M2;
		unordered_map<int, int> A1, A2;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				M1[i + j].push_back(grid[i][j]);
				if (M1[i + j].size() == 1)
					A1[i + j] = i;
				M2[i - j].push_back(grid[i][j]);
				if (M2[i - j].size() == 1)
					A2[i - j] = i;
			}
		unordered_map<int, vector<int>> P1;
		unordered_map<int, vector<int>> P2;
		for (auto& [key, value] : M1)
		{
			P1[key].push_back(0);
			partial_sum(value.begin(), value.end(), back_inserter(P1[key]));
		}
		for (auto& [key, value] : M2)
		{
			P2[key].push_back(0);
			partial_sum(value.begin(), value.end(), back_inserter(P2[key]));
		}
		auto sum1 = [&grid, &P1, &A1](int startI, int endI, int j)
		{
			int key = startI + j;
			int startPos = startI - A1[key];
			int endPos = startPos + endI - startI;
			if (startPos <= endPos)
				return P1[key][endPos + 1] - P1[key][startPos];
			return P1[key][startPos + 1] - P1[key][endPos];
		};
		auto sum2 = [&grid, &P2, &A2](int startI, int endI, int j)
		{
			int key = startI - j;
			int startPos = startI - A2[key];
			int endPos = startPos + endI - startI;
			if (startPos <= endPos)
				return P2[key][endPos + 1] - P2[key][startPos];
			return P2[key][startPos + 1] - P2[key][endPos];
		};
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				add(grid[i][j]);
				bool flag = true;
				for (int length = 2; ; ++length)
				{
					int x = i, y = j, total = 0;
					int nx = x + length - 1;
					int ny = y + length - 1;
					auto check = [N, M, &flag](int x, int y)
					{
						flag = (x >= 0 && y >= 0 && x < N && y < M);
						return flag;
					};
					if (!check(nx, ny))
						break;
					total += sum2(x, nx - 1, y);
					x = nx, y = ny;
					nx = x - length + 1;
					ny = y + length - 1;
					if (!check(nx, ny))
						break;
					total += sum1(x, nx + 1, y);
					x = nx, y = ny;
					nx = x - length + 1;
					ny = y - length + 1;
					if (!check(nx, ny))
						break;
					total += sum2(x, nx + 1, y);
					x = nx, y = ny;
					nx = x + length - 1;
					ny = y - length + 1;
					if (!check(nx, ny))
						break;
					total += sum1(x, nx - 1, y);
					add(total);
				}
			}
		result = vector<int>(S.begin(), S.end());
		sort(result.begin(), result.end(), greater<int>());
		return result;
	}
};