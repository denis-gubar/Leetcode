class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<int>> result(image);
		int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return result;
		int M = image.size(), N = image[0].size();
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		queue<int> Q;
		Q.push(sr); Q.push(sc);
		result[sr][sc] = newColor;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();			
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && result[nx][ny] == oldColor)
				{
					Q.push(nx); Q.push(ny);
					result[nx][ny] = newColor;
				}
			}
		}
		return result;
	}
};