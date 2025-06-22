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
    int kEmptySlots(vector<int>& bulbs, int K) {
        int const N = bulbs.size();
		FenwickTree<short> FT(N);
		vector<bool> visited(N);
		for (int i = 0; i < N; ++i)
		{
			int const bulb = bulbs[i] - 1;
			if (bulb > K && visited[bulb - K - 1] && FT.sum(bulb - K, bulb) == 0)
				return i + 1;
			if (bulb + K + 1 < N && visited[bulb + K + 1] && FT.sum(bulb + 1, bulb + K + 1) == 0)
				return i + 1;
			visited[bulb] = true;
			FT.add(bulb, 1);
		}
        return -1;
    }
};
