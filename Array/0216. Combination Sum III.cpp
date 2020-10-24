class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		for (int x = 1; x < 512; ++x)
		{
			int count = 0, sum = 0;
			vector<int>	digits;
			for (int d = 0; d < 9; ++d)
				if (x & (1 << d))
				{
					++count, sum += d + 1;
					digits.push_back(d + 1);
				}
			if (sum == n && count == k)
				result.push_back(digits);
		}
		return result;
	}
};