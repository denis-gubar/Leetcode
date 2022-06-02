class BookMyShow {
public:
	template<typename T>
	struct FenwickTree
	{
		FenwickTree(size_t N) : N(N)
		{
			tree.assign(N, {});
		}
		FenwickTree(vector<T> const& A) : FenwickTree(A.size())
		{
			for (size_t position = 0; position < N; ++position)
				add(position, A[position]);
		}
		void add(size_t position, T value)
		{
			for (size_t x = position; x < N; x |= x + 1)
				tree[x] += value;
		}
		// [0; position]
		T sum(size_t position)
		{
			T result{};
			for (size_t x = position; x > 0; x &= x - 1)
				result += tree[x - 1];
			return result;
		}
		// [left; right)
		T sum(size_t left, size_t right)
		{
			return sum(right) - sum(left);
		}
		size_t N;
		vector<T> tree;
	};
    template <typename T>
    struct SegmentTree
    {
        SegmentTree(int N) : N(1 << log2(N)), Tree(vector<T>((2 << log2(N)) + 1))
        {
        }
        void update(int pos, T value)
        {
            update(pos, value, 1, 0, N - 1);
        }
        T Max(int L, int R) const
        {
            return Max(L, R, 1, 0, N - 1);
        }
    private:
        int N;
        vector<T> Tree;
        static int log2(int x)
        {
            int result = 0;
            while (x)
            {
                x /= 2;
                ++result;
            }
            return result;
        }
        void update(int pos, T value, int root, int left, int right)
        {
            if (left == right)
                Tree[root] = value;
            else
            {
                int middle = (left + right) / 2;
                if (pos <= middle)
                    update(pos, value, root * 2, left, middle);
                else
                    update(pos, value, root * 2 + 1, middle + 1, right);
                Tree[root] = max(Tree[root * 2], Tree[root * 2 + 1]);
            }
        }
        T Max(int L, int R, int root, int left, int right) const
        {
            if (L > R)
                return 0;
            if (L == left && R == right)
                return Tree[root];
            int middle = (left + right) / 2;
            return max(Max(L, min(middle, R), root * 2, left, middle),
				Max(max(L, middle + 1), R, root * 2 + 1, middle + 1, right));
        }
    };
    BookMyShow(int n, int m): N(n), M(m), FT(N), R(0), S(N) {
		for (int i = 0; i < N; ++i)
		{
			FT.add(i, M);
			S.update(i, M);
		}
    }
    
    vector<int> gather(int k, int maxRow) {
		if (S.Max(0, maxRow) >= k)
		{
			int a = -1, b = maxRow;
			while (a + 1 < b)
			{
				int m = (a + b) / 2;
				if (S.Max(0, m) >= k)
					b = m;
				else
					a = m;
			}
			int row = b;
			int seats = FT.sum(row, row + 1);
			S.update(row, seats - k);
			FT.add(row, -k);
			return { row, M - seats };
		}		
		return {};
    }
    
    bool scatter(int k, int maxRow) {
		if (FT.sum(0, maxRow + 1) < k)
			return false;
		while (k > 0)
		{
			int emptySeats = FT.sum(R, R + 1);
			if (emptySeats == 0)
			{
				++R;
				continue;
			}
			if (emptySeats <= k)
			{				
				S.update(R, 0);
				k -= emptySeats;
				FT.add(R, -emptySeats);
				++R;
			}
			else
			{
				S.update(R, emptySeats - k);
				FT.add(R, -k);
				k = 0;
			}
		}
		return true;
    }
    int N, M, R;
	FenwickTree<long long> FT;
	SegmentTree<int> S;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
