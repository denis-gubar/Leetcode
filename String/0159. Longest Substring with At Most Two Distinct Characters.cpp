class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int result = 0;
		int a = 0, b = 0, distinct = 0;
		vector<int> count(128);
		while (b < s.size())
		{
			while (distinct > 2)
			{
				if (--count[s[a]] == 0)
					--distinct;
				++a;
			}
			if (++count[s[b]] == 1)
				++distinct;
			++b;
			if (distinct <= 2)
				result = max(result, b - a);
		}
		return result;
	}
};