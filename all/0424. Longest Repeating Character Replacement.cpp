class Solution {
public:
	int characterReplacement(string s, int k) {
		int result = 0;
		int N = s.size();
		int a = 0, b = 0;
		vector<int> count(26);
		int max_count = 0;
		while (b < N)
		{
			max_count = max(max_count, ++count[s[b] - 'A']);
			++b;
			while (b - a > k + max_count)
				--count[s[a] - 'A'], ++a;			
			result = max(result, b - a);
		}
		return result;
	}
};