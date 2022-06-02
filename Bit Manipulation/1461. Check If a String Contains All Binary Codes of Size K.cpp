class Solution {
public:
	bool hasAllCodes(string s, int k) {
		string t;
		vector<int> visited(1 << k);
		int total = 1 << k;
		int current = 0;
		for (int i = 0; i < k && i < s.size(); ++i)
		{
			current <<= 1;
			current += s[i] == '1';
		}
		if (++visited[current] == 1)
			--total;
		for (int i = k; i < s.size(); ++i)
		{
			current <<= 1;
			current &= (1 << k) - 1;
			current += s[i] == '1';
			if (++visited[current] == 1)
				--total;
		}
		return total == 0;
	}
};