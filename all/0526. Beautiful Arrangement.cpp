class Solution {
public:
	int countArrangement(int n) {
		int result = 0;
		unordered_map<int, int> M;
		M[0] = 1;
		for (int pos = 1; pos <= n; ++pos)
		{
			vector<pair<int, int>> A;
			for (int i = 1; i <= n; ++i)
				if (pos % i == 0 || i % pos == 0)
					for(auto [state, count] : M)
						if ((state & (1 << i)) == 0)
							A.emplace_back( state | (1 << i), count );
			M.clear();
			for (auto [state, count] : A)
				M[state] += count;
		}
		return M[(1 << (n + 1)) - 2];		
	}
};