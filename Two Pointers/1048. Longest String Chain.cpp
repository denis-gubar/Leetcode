class Solution {
public:
	bool check(string const& A, string const& B)
	{
		int a = 0, b = 0;
		int count = 0;
		while (a < A.size())
		{
			if (b < B.size())
			{
				if (A[a] != B[b])
					++count;
				else
					++b;
			}
			else
				++count;
			++a;
		}
		count += B.size() - b;
		return count == 1;
	}
	int longestStrChain(vector<string>& words) {
		vector<vector<string>> S(17);
		map<string, int> M;
		for (string const& word : words)
		{
			S[word.size()].push_back(word);
			M[word] = 1;
		}
		for (int i = 15; i >= 1; --i)
			for (string const& a : S[i + 1])
				for (string const& b : S[i])
					if (check(a, b))
						M[b] = max(M[b], M[a] + 1);
		int result = M.begin()->second;
		for (auto const& m : M)
			result = max(result, m.second);
        return result;
	}
};