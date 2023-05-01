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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        vector<int> A(nums);
        sort(A.begin(), A.end());
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]] = i;
        int pos = 0;
		FenwickTree<int> FT(N);
		for (int i = 0; i < N; ++i)
			FT.add(i, 1);
        for (int i = 0; i < N; ++i)
        {
            int newPos = M[A[i]];
			if (newPos >= pos)
				result += FT.sum(pos, newPos + 1);
			else
				result += FT.sum(0, newPos + 1) + FT.sum(pos, N);
			pos = newPos;
			FT.add(pos, -1);
        }
        return result;
    }
};
