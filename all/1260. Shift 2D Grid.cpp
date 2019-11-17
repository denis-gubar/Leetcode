class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		vector<vector<int>> result(grid);
		vector<int> plain;
		for (vector<int> const& row : grid)
			for (int x : row)
				plain.push_back(x);
        int N = plain.size();
		rotate(plain.begin(), plain.begin() + ((N - k) + 100 * N) % N, plain.end());
		int i = 0;
		for (vector<int>& row : result)
			for (int& x : row)
				x = plain[i], ++i;
		return result;
	}
};