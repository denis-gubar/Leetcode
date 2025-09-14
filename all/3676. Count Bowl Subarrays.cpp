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
    long long bowlSubarrays(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&nums](int a, int b)
            {
                if (nums[a] == nums[b])
                    return a < b;
                return nums[a] > nums[b];
            });
        set<int> S;
        S.insert(-1); S.insert(N);
		FenwickTree<int> FT(N);
        for (int i = 0; i < N; ++i)
        {            
            int j = i;
			for (; j < N && nums[I[j]] == nums[I[i]]; ++j)
				FT.add(I[j], 1);
            for (int k = i; k < j; ++k)
            {
				int const& pos = I[k];
                auto it = S.insert(pos).first;
				int left = *prev(it);
				if (left >= 0 && pos - 2 >= left)
					result += FT.sum(left, pos - 1);
				int right = *next(it);
				if (right < N && pos + 2 <= right)
					result += FT.sum(pos + 2, right + 1);									                
            }
        }
        return result;
    }
};
