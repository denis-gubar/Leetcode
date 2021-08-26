class Solution {
public:
	bool halvesAreAlike(string s) {
		string vowels{ "aeoiuAEIOU" };
		int a = 0, b = 0;
		int N = s.size();
		for (int i = 0; i < N / 2; ++i)
			if (vowels.find(s[i]) != string::npos)
				++a;
		for (int i = N / 2; i < N; ++i)
			if (vowels.find(s[i]) != string::npos)
				++b;
		return a == b;
	}
};