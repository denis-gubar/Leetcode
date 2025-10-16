class Solution {
public:
	string reverseStr(string s, int k) {
		int N = s.size();
		for (int start = 0; start < N; start += 2 * k)
		{
			int end = min(start + k, N);
			reverse(s.begin() + start, s.begin() + end);
		}
		return s;
	}
};