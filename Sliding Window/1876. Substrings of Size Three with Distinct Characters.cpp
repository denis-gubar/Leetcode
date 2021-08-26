class Solution {
public:
	int countGoodSubstrings(string s) {
		int result = 0;
		int N = s.size();
		for (int start = 0; start + 2 < N; ++start)
		{
			string t = s.substr(start, 3);
			sort(t.begin(), t.end());
			t.resize(unique(t.begin(), t.end()) - t.begin());
			if (t.size() == 3)
				++result;
		}
		return result;
	}
};