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
    long long minInversionCount(vector<int>& nums, int K) {
        long long result = 1LL << 60;
        vector<int> A(nums);
		A.push_back(-1);
        sort(A.begin(), A.end());
        A.resize(unique(A.begin(), A.end()) - A.begin());
        int const N = nums.size(), AN = A.size();
        unordered_map<int, int> M;
        for (int i = 0; i < AN; ++i)
            M[A[i]] = i;
		FenwickTree<int> FT(AN);
		long long invCount = 0;
		for (int i = 0; i < N; ++i)
		{
			FT.add(M[nums[i]], 1);
			invCount += FT.sum(M[nums[i]] + 1, AN);
			if (i >= K)
			{
				FT.add(M[nums[i - K]], -1);
				invCount -= FT.sum(0, M[nums[i - K]]);
			}
			if (i >= K - 1)
				result = min(result, invCount);
		}
        return result;
    }
};
