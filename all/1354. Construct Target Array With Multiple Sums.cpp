class Solution {
public:
	bool isPossible(vector<int>& target) {
		long long total = accumulate(target.begin(), target.end(), 0LL);
		map<int, int> M;
		multiset<int> S;
		for (int t : target)
			++M[-t];
		while (-M.begin()->first > 1)
		{
			int x = -M.begin()->first;
			if (M.begin()->second == 1)
				M.erase(M.begin());
			else
				--M[-x];
			long long delta = total - x;
			if (x <= delta || delta == 0)
				return false;
			x -= delta;
            total -= delta;
			++M[-x];
		}
		return true;
	}
};