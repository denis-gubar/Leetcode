class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		int result = 0;
		int A = 1 << 30;
		for (vector<int> const& nut : nuts)
		{
			result += 2 * (abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]));
			A = min(A, -abs(nut[0] - tree[0]) - abs(nut[1] - tree[1]) +
						abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]));
		}
		result += A;
		return result;
	}
};