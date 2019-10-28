class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int result = 0;
		int a = 0, b = 0, distinct = 0;
		vector<int> A(128);
		while (b < s.size())
		{
			while (distinct > k)
			{
				if (--A[s[a]] == 0)
					--distinct;
				++a;
			}
			if (++A[s[b]] == 1)
				++distinct;
			++b;
            if (distinct <= k)
			    result = max(result, b - a);
		}
		return result;
	}
};