class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
		set<string> S;
		int N = A[0].size();
		for (const string& s : A)
		{
			string a, b;
			for (int i = 0; i < N; i += 2)
				a +=s[i];
			for (int i = 1; i < N; i += 2)
				b += s[i];
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			S.insert(a + b);
		}
		return S.size();
	}
};
