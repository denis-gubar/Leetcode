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
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        vector<long long> result;
        int N = nums.size();
		FenwickTree<long long> FT(N + 2);
		for (int i = 0; i < N; ++i)
			FT.add(i + 1, nums[i]);
		set<pair<long long, int>> S;
		set<int> Z;
		long long total = FT.sum(0, N + 1);
		S.insert({ 0, -1 });
		S.insert({ total, 0 });
		Z.insert(-1);
		Z.insert(N);
		for (int Q : removeQueries)
		{
			FT.add(Q + 1, -nums[Q]);
			auto it = Z.lower_bound(Q);
			auto prev_it = prev(it);
			int pos = *it;
			int prev_pos = *prev_it;
			long long value = FT.sum(prev_pos + 1, pos + 1);
			value += nums[Q];
			S.erase(S.find({ value, prev_pos + 1 }));
			long long left = FT.sum(prev_pos + 1, Q + 1);
			long long right = FT.sum(Q + 1, pos + 1);
			if (left > 0)
				S.insert({left, prev_pos + 1});
			if (right > 0)
				S.insert({ right, Q + 1 });
			Z.insert(Q);
			nums[Q] = 0;
			result.push_back(S.rbegin()->first);
		}
        return result;
    }
};
