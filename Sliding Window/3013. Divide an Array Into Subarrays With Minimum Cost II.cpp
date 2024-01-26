class Solution {
public:
	struct SegmentTree {

		struct Node {
			long long sum;
			int count;
			int left, right;
		};

		int mn, mx;
		vector<int> roots;
		vector<Node> tree;

		SegmentTree(vector<int> const & A) : mn(1 << 30), mx(-(1 << 30)), roots(A.size() + 1)
		{
			tree.reserve(1 << 20);
			tree.push_back({ 0, 0, 0 }); //acts as null
			for (int val : A) mn = min(mn, val), mx = max(mx, val);
			for (int i = 0; i < (int)A.size(); i++)
				roots[i + 1] = update(roots[i], -mx, mx, A[i]);
		}
		int update(int v, int tL, int tR, int i) {
			if (tL == tR)
			{
				tree.push_back({ tree[v].sum + tL, tree[v].count + 1, 0, 0 });
				return tree.size() - 1;
			}
			int tm = tL + (tR - tL) / 2;
			int lCh = tree[v].left;
			int rCh = tree[v].right;
			if (i <= tm)
				lCh = update(lCh, tL, tm, i);
			else
				rCh = update(rCh, tm + 1, tR, i);
			tree.push_back({ tree[lCh].sum + tree[rCh].sum, tree[lCh].count + tree[rCh].count, lCh, rCh });
			return tree.size() - 1;
		}

		long long query_sum(int L, int R, int K)
		{
			return query_sum(roots[L], roots[R + 1], -mx, mx, K);
		}
		long long  query_sum(int vL, int vR, int tL, int tR, int k)
		{
			if (tL == tR)
				return 1LL * tL * k;
			int tm = tL + (tR - tL) / 2;
			int left_count = tree[tree[vR].left].count - tree[tree[vL].left].count;
			long long left_sum = tree[tree[vR].left].sum - tree[tree[vL].left].sum;
			if (left_count >= k)
				return query_sum(tree[vL].left, tree[vR].left, tL, tm, k);
			return left_sum + query_sum(tree[vL].right, tree[vR].right, tm + 1, tR, k - left_count);
		}
	};
    long long minimumCost(vector<int>& nums, int K, int dist) {
        int N = nums.size();
		long long result = 1LL << 60;
		SegmentTree ST(nums);
        for (int i = N - 1; i >= K - 1; --i)
        {
			long long sum = ST.query_sum(max(1, i - dist), i - 1, K - 2) + nums[0] + nums[i];
            result = min(result, sum);
        }
        return result;
    }
};
