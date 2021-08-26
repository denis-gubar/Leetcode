class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int N = s.size();        
		for(int x = 1; 2 * x <= N; ++x)
			if (N % x == 0 && N / x > 1)
			{
				bool found = false;
				for (int i = 0; !found && i < N; ++i)
					found |= s[i] != s[i % x];
				if (!found)
					return true;
			}
		return false;
	}
};