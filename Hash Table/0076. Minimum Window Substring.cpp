class Solution {
public:
	string minWindow(string s, string t) {
		string result;
		vector<int> counts(128), limits(128);
		for (int c : t)
			++limits[c];
		int a = 0, b = 0, distinctCount = 0;
		while (true)
		{
			while (distinctCount == t.size())
			{
				if (result.empty() || result.size() > b - a)
					result = s.substr(a, b - a);
				if (limits[s[a]] > --counts[s[a]])
					--distinctCount;
				++a;
			}
			if (b == s.size())
				break;
			if (limits[s[b]] >= ++counts[s[b]])
				++distinctCount;
			++b;
		}
		return result;
	}
};