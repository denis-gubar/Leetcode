class Solution {
public:
	int getMask(int mask, char c)
	{
		int result = mask;
		string vowels{ "aeiou" };
		auto x = vowels.find(c);
		if (x != string::npos)
			result ^= 1 << x;
		return result;
	}
	int findTheLongestSubstring(string s) {
		int result = 0;
		int N = s.size();
		vector<vector<int>> count(1 << 5);
		int mask = 0;
        count[0].push_back(0);
		for (int i = 0; i < N; ++i)
		{
			char c = s[i];
			mask = getMask(mask, c);
			count[mask].push_back(i + 1);
		}
		for (int mask = 0; mask < (1 << 5); ++mask)
		{
			vector<int> const& A = count[mask];
			if (!A.empty())
				result = max(result, A.back() - A[0]);
		}
		return result;
	}
};