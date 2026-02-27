class Solution {
public:
	vector<int> sortByBits(vector<int> arr) {
		sort(arr.begin(), arr.end(), [&](unsigned int a, unsigned int b)
			{
				int A = popcount(a), B = popcount(b);
				if (A != B)
					return A < B;
				return a < b;
			});
		return arr;
	}
};