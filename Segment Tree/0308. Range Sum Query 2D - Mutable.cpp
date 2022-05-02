class NumMatrix {
public:
	template<typename T>
	struct FenwickTree2D
	{
		FenwickTree2D(size_t N, size_t M) : N(N), M(M)
		{
			tree.assign(N, vector<T>(M));
		}
		FenwickTree2D(vector<vector<T>> const& A) : FenwickTree2D(A.size(), A[0].size())
		{
			for (size_t positionX = 0; positionX < N; ++positionX)
				for (size_t positionY = 0; positionY < M; ++positionY)
					add(positionX, positionY, A[positionX][positionY]);
		}
		void add(size_t positionX, size_t positionY, T value)
		{
			for (size_t x = positionX; x < N; x |= x + 1)
				for (size_t y = positionY; y < M; y |= y + 1)
					tree[x][y] += value;
		}
		// [0; positionX] x [0; positionY]
		T sum(size_t positionX, size_t positionY)
		{
			T result{};
			for (size_t x = positionX; x > 0; x &= x - 1)
				for (size_t y = positionY; y > 0; y &= y - 1)
					result += tree[x - 1][y - 1];
			return result;
		}
		// [leftX; leftY) x [rightX; rightY)
		T sum(size_t leftX, size_t leftY, size_t rightX, size_t rightY)
		{
			return sum(rightX, rightY)
				- sum(leftX, rightY)
				- sum(rightX, leftY)
				+ sum(leftX, leftY);
		}
		size_t N, M;
		vector<vector<T>> tree;
	};
    NumMatrix(vector<vector<int>>& matrix): matrix(matrix), ft(matrix) {
        
    }
    
    void update(int row, int col, int val) {
		int delta = val - matrix[row][col];
		matrix[row][col] = val;
		ft.add(row, col, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		return ft.sum(row1, col1, row2 + 1, col2 + 1);
    }
	vector<vector<int>> matrix;
	FenwickTree2D<int> ft;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
