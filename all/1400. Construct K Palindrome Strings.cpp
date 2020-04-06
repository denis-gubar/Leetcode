class Solution {
public:
	bool canConstruct(string s, int k) {
		if (k > s.size()) return false;
		vector<int> A(26);
		for (char c : s)
			++A[c - 'a'];
		int odd = 0, even = 0;
		for(int a: A)
			if (a)
			{
				odd += a % 2;
				even += a % 2 == 0;
			}
		return odd <= k;
	}
};