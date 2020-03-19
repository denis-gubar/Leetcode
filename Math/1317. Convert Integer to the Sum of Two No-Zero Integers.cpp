class Solution {
public:
	bool check(int x)
	{
		return to_string(x).find('0') == string::npos;
	}
	vector<int> getNoZeroIntegers(int n) {
		vector<int> result;
		for (int x = 1; x < n; ++x)
			if (check(x) && check(n - x))
				return { x, n - x };
		return result;
	}
};