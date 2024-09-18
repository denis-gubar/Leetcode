class Solution {
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
		// [0; position)
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
    int numTeams(vector<int>& rating) {
        int result = 0;
        int const N = rating.size();
		vector<int> I(N);
		iota(I.begin(), I.end(), 0);
		sort(I.begin(), I.end(), [&rating](int a, int b)
			{
				return rating[a] < rating[b];
			});
		for (int k = 0; k < 2; ++k)
		{
			FenwickTree<int> FT(N), FT2(N);
			for (int i = 0; i < N; ++i)
			{
				int const pos = I[i];
				result += FT2.sum(pos);
				FT2.add(pos, FT.sum(pos));
				FT.add(pos, 1);
			}
			reverse(I.begin(), I.end());
		}
        return result;
    }
};
