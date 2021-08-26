class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		int N = books.size();
		vector<int>	F(N + 1, 1'000'000);
		F[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			int width = 0, height = 0;
			for (int j = i; j < N; ++j)
			{
				width += books[j][0];
				if (width > shelf_width)
					break;
				height = max(height, books[j][1]);
				F[j + 1] = min(F[j + 1], F[i] + height);
			}
		}
		return F[N];
	}
};