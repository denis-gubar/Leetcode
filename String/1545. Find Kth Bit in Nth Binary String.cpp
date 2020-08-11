class Solution {
public:
	char findKthBit(int n, int k) {
		string s{ '0' };
		s.reserve(1 << n);
		for (int t = 2; t <= n; ++t)
		{
			s.push_back('1');
			for (int pos = s.size() - 2; pos >= 0; --pos)
				s.push_back('0' + '1' - s[pos]);
		}
		return s[k - 1];
	}
};