template<typename T>
struct FenwickTree
{
	void clear()
	{
		tree.assign(N, {});
	}
	FenwickTree(size_t N) : N(N)
	{
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
static FenwickTree<long long> FT(200'001);
class Solution {
public:	
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
		FT.clear();
        long long result = 0;
        int N = nums1.size();
		for (int i = 0; i < N; ++i)
		{
			int delta = nums1[i] - nums2[i];
			result += FT.sum(-delta + 100'001, 200'001);
			FT.add(delta + 100'000, 1);
		}
        return result;
    }
};
