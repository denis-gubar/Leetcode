class Solution {
public:
	bool isPathCrossing(string path) {
		set<pair<int, int>> S;
		S.emplace(0, 0);
		int x = 0, y = 0;
		for (char c : path)
		{
			if (c == 'N')
				++x;
			if (c == 'S')
				--x;
			if (c == 'E')
				++y;
			if (c == 'W')
				--y;
			if (!S.emplace(x, y).second)
				return true;
		}
		return false;
	}
};