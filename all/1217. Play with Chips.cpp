class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		int a = 0, b = 0;
		for (int i = 0; i < chips.size(); ++i)
			if (chips[i] % 2 == 0)
				++a;
			else
				++b;
		return min(a, b);
	}
};