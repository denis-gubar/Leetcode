class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int result = 0;
		int a = 0, b = 0, cost = 0;
		while (b < s.size())
		{
			cost += abs(t[b] - s[b]);
			while (cost > maxCost)
			{
				cost -= abs(t[a] - s[a]);
				++a;
			}
			result = max(result, b - a + 1);
			++b;
		}
		return result;
	}
};