class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
        if (s.empty() || s.size() < p.size()) return result;
		vector<int> pattern(26);
		for (char c : p)
			++pattern[c - 'a'];
		vector<int> current(26);
		for (int i = 0; i < p.size(); ++i)
			++current[s[i] - 'a'];
		if (pattern == current)
			result.push_back(0);
		for (int i = 0; i + p.size() < s.size(); ++i)
		{
			--current[s[i] - 'a'];
			++current[s[i + p.size()] - 'a'];
			if (pattern == current)
				result.push_back(i + 1);
		}
		return result;
	}
};