class Solution {
public:
	int hungarian(vector<vector<int>>& matrix)
	{
		int N = matrix.size(), M = matrix[0].size();

		vector<int> u(N, 0), v(M, 0);

		vector<int> markIndices(M, -1);

		for (int i = 0; i < N; i++)
		{
			vector<int> links(M, -1);
			vector<int> mins(M, 1 << 30);
			vector<int> visited(M, 0);
			int markedI = i, markedJ = -1, j;
			while (markedI != -1) {
				j = -1;
				for (int j1 = 0; j1 < M; j1++)
					if (!visited[j1])
					{
						if (matrix[markedI][j1] - u[markedI] - v[j1] < mins[j1])
						{
							mins[j1] = matrix[markedI][j1] - u[markedI] - v[j1];
							links[j1] = markedJ;
						}
						if (j == -1 || mins[j1] < mins[j])
							j = j1;
					}
				int delta = mins[j];
				for (int j1 = 0; j1 < M; j1++)
					if (visited[j1]) {
						u[markIndices[j1]] += delta;
						v[j1] -= delta;
					}
					else {
						mins[j1] -= delta;
					}
				u[i] += delta;

				visited[j] = 1;
				markedJ = j;
				markedI = markIndices[j];
			}
			for (; links[j] != -1; j = links[j])
				markIndices[j] = markIndices[links[j]];
			markIndices[j] = i;
		}

		int result = 0;
		for (int j = 0; j < M; j++)
			if (markIndices[j] != -1)
				result += matrix[markIndices[j]][j];
		return result;
	}
	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {		
		int N = nums1.size();
		vector<vector<int>> matrix(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				matrix[i][j] = nums1[i] ^ nums2[j];
		return hungarian(matrix);
	}
};