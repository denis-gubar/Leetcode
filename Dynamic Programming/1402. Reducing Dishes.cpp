class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		int result = 0;
		sort(satisfaction.begin(), satisfaction.end());
		vector<int> A;
		partial_sum(satisfaction.rbegin(), satisfaction.rend(), back_inserter(A));
		for (int a : A)
			if (a > 0)
				result += a;
		return result;
	}
};