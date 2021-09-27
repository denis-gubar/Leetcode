class Solution {
public:
	vector<vector<int>> children;
	void calc(int V, vector<bool>& F, vector<int> const& nums)
	{
		F[nums[V]] = true;
		for (int U : children[V])
			calc(U, F, nums);
	}
	vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
		int N = nums.size();
		vector<int> result(N, 1);
		children = vector<vector<int>>(N);
		for(int i = 1; i < N; ++i)
			children[parents[i]].push_back(i);
		vector<int>	A(100'001, -1);
		vector<bool> F(100'002);
		for (int i = 0; i < N; ++i)
			A[nums[i]] = i;
		int V = A[1];
		int j = 1;
		while (V != -1)
		{
			F[nums[V]] = true;
			for (int U : children[V])
			{
				if (F[nums[U]])
					continue;
				calc(U, F, nums);
			}
			while (F[j])
				++j;
			result[V] = j;
			V = parents[V];
		}
		return result;
	}
};