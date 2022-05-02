class Solution {
public:
	bool judgeCircle(string moves) {
		int D = count(moves.begin(), moves.end(), 'D');
		int U = count(moves.begin(), moves.end(), 'U');
		int L = count(moves.begin(), moves.end(), 'L');
		int R = count(moves.begin(), moves.end(), 'R');
		return D == U && L == R;
	}
};