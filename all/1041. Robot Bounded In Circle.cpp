class Solution {
public:
	bool isRobotBounded(string instructions) {
		int x = 0, y = 0, dir = 0;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		for (int k = 0; k < 4; ++k)
			for (char c : instructions)
				if (c == 'G')
					x += dx[dir], y += dy[dir];
				else if (c == 'L')
					dir = (dir + 3) % 4;
				else if (c == 'R')
					dir = (dir + 1) % 4;
		return x == 0 && y == 0;
	}
};