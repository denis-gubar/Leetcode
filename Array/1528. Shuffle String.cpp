class Solution {
public:
	string restoreString(string s, vector<int>& indices) {
		int N = s.size();
		string result(N, ' ');
		for (int i = 0; i < N; ++i)
			result[indices[i]] = s[i];
		return result;
	}
};