class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		int result = 0;
		vector<int> A;
		for (vector<int> const& nut : nuts)
		{
			result += 2 * (abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]));
			A.push_back(-abs(nut[0] - tree[0]) - abs(nut[1] - tree[1]) +
						abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]));
		}
		result += *min_element(A.begin(), A.end());
		return result;
	}
};