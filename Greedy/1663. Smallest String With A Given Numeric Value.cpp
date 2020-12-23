class Solution {
public:
	string getSmallestString(int n, int k) {
		string result(n, 'a');
		k -= n;
		for (int i = n - 1; k > 0 && i >= 0; --i)
		{
			int delta = min(25, k);
			k -= delta;
			result[i] += delta;
		}
		return result;
	}
};