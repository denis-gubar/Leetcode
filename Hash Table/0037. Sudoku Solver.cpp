class Solution {
public:
	vector<vector<pair<int, int>>> blocks;
	map<pair<int, int>, vector<int>> inv;
	vector<int> options;
	bool calc(vector<vector<char>>& board, vector<pair<int, int>> const& order, int step)
	{
		if (step == order.size())
			return true;
		auto [x, y] = order[step];
		int mask = (1 << 9) - 1;
		for (int blockId : inv[{x, y}])
			mask &= options[blockId];
		while (mask)
		{
			int highBit = ilogb(mask);
			mask ^= 1 << highBit;
			for (int blockId : inv[{x, y}])
				options[blockId] ^= 1 << highBit;
			board[x][y] = '1' + highBit;
			if (calc(board, order, step + 1))
				return true;
			for (int blockId : inv[{x, y}])
				options[blockId] ^= 1 << highBit;
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		blocks.clear();
		inv.clear();
		for (int x = 0; x < 9; ++x)
		{
			int blockId = blocks.size();
			blocks.push_back({});
			for (int y = 0; y < 9; ++y)
			{
				blocks.back().push_back({ x, y });
				inv[{x, y}].push_back(blockId);
			}
		}
		for (int y = 0; y < 9; ++y)
		{
			int blockId = blocks.size();
			blocks.push_back({});
			for (int x = 0; x < 9; ++x)
			{
				blocks.back().push_back({ x, y });
				inv[{x, y}].push_back(blockId);
			}
		}
		for (int blockX = 0; blockX < 3; ++blockX)
			for (int blockY = 0; blockY < 3; ++blockY)
			{
				int blockId = blocks.size();
				blocks.push_back({});
				for (int x = blockX * 3; x < (blockX + 1) * 3; ++x)
					for (int y = blockY * 3; y < (blockY + 1) * 3; ++y)
					{
						blocks.back().push_back({ x, y });
						inv[{x, y}].push_back(blockId);
					}
			}
		vector<int> capacityReserved(27);
		options = vector<int>(27, (1 << 9) - 1);
		auto getReservation = [this, &capacityReserved](int x, int y)
		{
			int result = 0;
			for (int blockId : inv[{x, y}])
				result += capacityReserved[blockId];
			return result;
		};
		auto comp = [&getReservation](pair<int, int> a, pair<int, int> b)
		{
			int reservationA = getReservation(a.first, a.second);
			int reservationB = getReservation(b.first, b.second);
			if (reservationA != reservationB)
				return reservationA > reservationB;
			return a < b;
		};
		set<pair<int, int>, decltype(comp)> S(comp);
		for (int x = 0; x < 9; ++x)
			for (int y = 0; y < 9; ++y)
				if (board[x][y] != '.')
				{
					for (int blockId : inv[{x, y}])
					{
						++capacityReserved[blockId];
						options[blockId] ^= 1 << (board[x][y] - '1');
					}
				}
		for (int x = 0; x < 9; ++x)
			for (int y = 0; y < 9; ++y)
				if (board[x][y] == '.')
					S.insert({ x, y });
		vector<pair<int, int>> order;
		while (!S.empty())
		{
			auto it = S.begin();
			auto [x, y] = *it;
			order.emplace_back(x, y);
			S.erase(it);
			board[x][y] = '0';
			for (int blockId : inv[{x, y}])
			{
				vector<pair<int, int>> points;
				for (auto [nx, ny] : blocks[blockId])
					if (board[nx][ny] == '.')
						points.emplace_back(nx, ny);
				for (auto [nx, ny] : points)
					S.erase(S.find({ nx, ny }));
				++capacityReserved[blockId];
				for (auto [nx, ny] : points)
					S.insert({ nx, ny });
			}
		}
		calc(board, order, 0);
	}
};