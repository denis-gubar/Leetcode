class Solution {
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int M = rolls.size();
		vector<int> result(n);		
		int total = accumulate(rolls.begin(), rolls.end(), 0);
		int delta = mean * (n + M) - total;
		if (delta < n || delta > n * 6)
			return {};
		for (int i = 0; i < n; ++i)
		{
			result[i] = min(delta - (n - i - 1), 6);
			delta -= result[i];
		}
		return result;
	}
};