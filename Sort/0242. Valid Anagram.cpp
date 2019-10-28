class Solution {
public:
	vector<int> calc(const string& s)
	{
		vector<int> result(26);
		for (int c : s)
			++result[c - 'a'];
		return result;
	}
	bool isAnagram(const string& s, const string& t) {
		return s.size() == t.size() && calc(s) == calc(t);
	}
};