class Solution {
public:
	int maxProduct(vector<string>& words) {
		int result = 0;
		vector<int> A;
		for (string const& s : words)
		{
			A.push_back(0);
			for (char c : s)
				A.back() |= 1 << (c - 'a');
		}
		int N = words.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				if ((A[i] & A[j]) == 0)
					result = max<int>(result, words[i].size() * words[j].size());
		return result;
	}
};