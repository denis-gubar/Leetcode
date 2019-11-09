class Solution {
public:
	bool canCross(vector<int>& stones) {
		int N = stones.size();
		vector<set<int>> states(N);
		map<int, int> Inv;
		for (int i = 1; i < N; ++i)
			Inv[stones[i]] = i;
		states[0] = { 0 };
		for (int i = 0; i + 1 < N; ++i)
			for (int k : states[i])
				for (int delta = -1; delta <= 1; ++delta)
					if (k + delta > 0 && Inv.find(stones[i] + k + delta) != Inv.end())
						states[Inv[stones[i] + k + delta]].insert(k + delta);
		return !states.back().empty();
	}
};