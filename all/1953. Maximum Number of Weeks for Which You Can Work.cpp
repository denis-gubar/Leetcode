class Solution {
public:
	long long numberOfWeeks(vector<int>& milestones) {
		int N = milestones.size();
		if (N == 1)
			return 1;
		sort(milestones.begin(), milestones.end());
		long long total = accumulate(milestones.begin(), milestones.begin() + (N - 1), 0LL);
		if (total >= milestones.back() - 1)
			return total + milestones.back();
		return total * 2 + 1;
	}
};