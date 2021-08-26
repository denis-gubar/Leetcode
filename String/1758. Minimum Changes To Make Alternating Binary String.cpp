class Solution {
public:
	int minOperations(string s) {
		int N = s.size();
		int a = 0, b = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] % 2 == i % 2)
				++a;
			if (s[i] % 2 == (i + 1) % 2)
				++b;
		}
		return min(a, b);
	}
};