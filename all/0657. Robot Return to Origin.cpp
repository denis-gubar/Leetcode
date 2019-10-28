class Solution {
public:
	bool judgeCircle(string moves) {
		return count(moves.begin(), moves.end(), 'U') == count(moves.begin(), moves.end(), 'D') &&
			count(moves.begin(), moves.end(), 'L') == count(moves.begin(), moves.end(), 'R');
	}
};