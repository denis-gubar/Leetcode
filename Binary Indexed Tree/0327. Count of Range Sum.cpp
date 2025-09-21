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
			if (right <= left)
				return 0;
			return sum(right) - sum(left);
		}
		size_t N;
		vector<T> tree;
	};
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int result = 0;
        set<long long> S;
        long long const INF = 1LL << 40;
        S.insert(-INF);
        S.insert(0LL);
        S.insert(INF);        
        long long total = 0;
        for (int x : nums)
        {
            total += x;
            S.insert(total);
        }
        int const N = S.size();
        unordered_map<long long, int> M;
        vector<long long> A(S.begin(), S.end());
        for (int i = 0; i < N; ++i)
            M[A[i]] = i;
		FenwickTree<int> FT(N);
        total = 0LL;
		FT.add(M[total], 1);
		for (int x : nums)
		{
			total += x;
			result +=  FT.sum(lower_bound(A.begin(), A.end(), total - upper) - A.begin(),
				upper_bound(A.begin(), A.end(), total - lower) - A.begin());
			FT.add(M[total], 1);
		}
        return result;
    }
};
