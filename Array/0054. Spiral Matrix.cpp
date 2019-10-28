class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
        if (matrix.empty())
            return {};
		int x = 0, y = -1, d = 0;
		int kx = matrix.size(), ky = matrix[0].size();
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		while (ky)
		{
			for (int k = 0; k < ky; ++k)
			{
				x += dx[d], y += dy[d];
				result.push_back(matrix[x][y]);
			}
            d = (d + 1) % 4;
			swap(kx, ky);
			--ky;
		}
		return result;
	}
};