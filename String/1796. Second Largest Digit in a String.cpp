class Solution {
public:
	int secondHighest(string s) {
		set<int> S;
		for (char c : s)
			if (isdigit(c))
				S.insert(c - '0');
		auto it = S.end();
		for (int i = 0; i < 2; ++i)
		{
			if (it == S.begin())
				return -1;
			--it;
		}
		return *it;
	}
};