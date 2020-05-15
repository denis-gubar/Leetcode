class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) return false;
		vector<int> A(26), B(26);
		for (char a : s1)
			++A[a - 'a'];
		for (int i = 0; i < s1.size(); ++i)
			++B[s2[i] - 'a'];
		if (A == B)
			return true;
		for (int i = 0; i + s1.size() < s2.size(); ++i)
		{
			--B[s2[i] - 'a'];
			++B[s2[i + s1.size()] - 'a'];
			if (A == B)
				return true;
		}
		return false;
	}
};