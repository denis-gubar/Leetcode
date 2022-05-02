class Solution {
public:
	bool isSameAfterReversals(int num) {
		string s = to_string(num);
		reverse(s.begin(), s.end());
		s = to_string(stoi(s));
		reverse(s.begin(), s.end());
		return stoi(s) == num;
	}
};