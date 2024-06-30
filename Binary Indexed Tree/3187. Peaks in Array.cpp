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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size(), N = nums.size();
        vector<int> result;
		result.reserve(Q);
		FenwickTree<int> FT(N + 1);
		for (int i = 1; i < N - 1; ++i)
			if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
				FT.add(i, 1);
        for (int q = 0; q < Q; ++q)
        {
            int const& type = queries[q][0];
            if (type == 1)
            {
                int const& L = queries[q][1];
                int const& R = queries[q][2];
				if (R - L < 2)
					result.push_back(0);
				else
					result.push_back(FT.sum(L + 1, R));
				continue;
            }
            int const& index = queries[q][1];
            int const& val = queries[q][2];
			for (int i = index - 1; i <= index + 1; ++i)
			{
				if (i >= 0 && FT.sum(i, i + 1) == 1)
					FT.add(i, -1);
			}
			nums[index] = val;
			for (int i = index - 1; i <= index + 1; ++i)
				if (i > 0 && i < N - 1 && nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
					FT.add(i, 1);
        }
        return result;
    }
};
