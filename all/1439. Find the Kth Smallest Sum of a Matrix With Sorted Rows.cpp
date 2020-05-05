class Solution {
public:
	int kthSmallest(vector<vector<int>>& mat, int k) {
		int N = mat.size(), M = mat[0].size();		
		vector<int> sums{ 0 };
		for (int i = 0; i < N; ++i)
		{
			vector<int> next;
			for (int s : sums)
				for (int n : mat[i])
					next.push_back(s + n);
			sort(next.begin(), next.end());
			if (next.size() > k)
				next.resize(k);
			sums = move(next);
		}
		return sums[k - 1];
	}
};