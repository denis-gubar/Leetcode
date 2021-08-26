class Solution {
public:
	int f(int x)
	{
		int result = 0;
		while (x)
		{
			x &= x - 1;
			++result;
		}
		return result;
	}
	vector<int> sortByBits(vector<int> arr) {
		sort(arr.begin(), arr.end(), [&](int a, int b)
			{
				int A = f(a), B = f(b);
				if (A != B)
					return A < B;
				return a < b;
			});
		return arr;
	}
};