class Solution {
public:
	bool makeEqual(vector<string>& words) {
		vector<int> A(26);
		int N = words.size();
		for (int i = 0; i < N; ++i)
			for (char c : words[i])
				++A[c - 'a'];
		for (int x = 0; x < 26; ++x)
			if (A[x] % N != 0)
				return false;
		return true;
	}
};