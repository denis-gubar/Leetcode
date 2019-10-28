class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		int N = books.size();
		vector<int> M(N + 1);
		for (int i = 0; i < N; ++i)
			M[i + 1] = M[i] + books[i][1];
		for (int book = 1; book < N; ++book)
		{
			int width = 0, startBook = book, height = 0;
			while (startBook >= 0 && width + books[startBook][0] <= shelf_width)
			{
				height = max(height, books[startBook][1]);
				width += books[startBook][0];
				M[book + 1] = min(M[book + 1], height + M[startBook]);
                --startBook;
			}			
		}
		return M[N];
	}
};