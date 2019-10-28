class Solution {
public:
	int sign(int x)
	{
		if (x == 0)
			return 0;
		if (x < 0)
			return -1;
		return 1;
	}
	string alphabetBoardPath(string target) {
		vector<string> board{ "abcde", "fghij", "klmno", "pqrst", "uvwxy", "z" };
		int x = 0, y = 0;
		vector<int> bx(128), by(128);
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				bx[board[i][j]] = i, by[board[i][j]] = j;
		map<int, char> dx, dy;
		dx[-1] = 'U'; dx[0] = 0; dx[1] = 'D';
		dy[-1] = 'L'; dy[0] = 0; dy[1] = 'R';
		string result;
		for (char c : target)
		{
			int nx = bx[c], ny = by[c];
			char cx = dx[sign(nx - x)], cy = dy[sign(ny - y)];
			while (x != nx || y != ny)
			{
				for (; x != nx && y < board[x + sign(nx - x)].size(); x += sign(nx - x))
					result += cx;
				for (; y != ny && y + sign(ny - y) < board[x].size(); y += sign(ny - y))
					result += cy;
			}
			result += '!';
		}
		return result;
	}
};