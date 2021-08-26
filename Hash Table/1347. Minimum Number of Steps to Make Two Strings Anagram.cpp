class Solution {
public:
	int minSteps(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		string result;
		set_difference(s.begin(), s.end(), t.begin(), t.end(), back_inserter(result));
		return result.size();
	}
};