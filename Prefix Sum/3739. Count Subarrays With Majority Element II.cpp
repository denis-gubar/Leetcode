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
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long result = 0;
        int const N = nums.size(), M = N + 1;
        int balance = 0;            
		FenwickTree<long long> FT(M + M);
		FT.add(M, 1);
		for (int i = 0; i < N; ++i)
		{
			balance += 2 * (nums[i] == target) - 1;
			result += FT.sum(0, M + balance);
			FT.add(M + balance, 1);
		}
        return result;
    }
};
