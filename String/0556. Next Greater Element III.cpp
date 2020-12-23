class Solution {
public:
	int nextGreaterElement(int n) {
		string s(to_string(n));
		next_permutation(s.begin(), s.end());
		long long result = atoll(s.c_str());
		if (result <= n || result >= (1LL << 31))
			return -1;
		return result;
	}
};