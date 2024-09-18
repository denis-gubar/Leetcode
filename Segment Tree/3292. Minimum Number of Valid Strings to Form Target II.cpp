static vector<int> z_function(string const& s)
{
	int N = s.size();
	vector<int> z(N);
	for (int i = 1, L = 0, R = 1; i < N; ++i)
	{
		if (i < R)
			z[i] = min(R - i, z[i - L]);
		while (i + z[i] < N && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] > R)
			L = i, R = i + z[i];
	}
	return z;
}
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int const W = words.size(), N = target.size();
        vector<int> D(N, 0);
		string S;
		S.reserve(1 << 18);
		for (string const& w : words)
		{
			S.clear();
			S += w;
			S += '#';
			S += target;
			vector<int> Z = z_function(S);
			for (int i = w.size() + 1, j = 0; i < S.size(); ++i, ++j)
				D[j] = max(D[j], Z[i]);
		}
		vector<int> A;
		A.reserve(N);
		A.push_back(0);
		for (int i = 0; i < N; ++i)
		{
			if (A.back() < i)
				break;
			if (D[i] > 0)
			{
				auto it = lower_bound(A.begin(), A.end(), i);
				if (it == A.end())
					A.push_back(i + D[i]);
				else
				{
					if (next(it) == A.end())
					{
						if (A.back() < i + D[i])
							A.push_back(i + D[i]);
					}
					else if (*next(it) < i + D[i])
						*next(it) = i + D[i];
				}
			}
		}
        int result = -1;
		if (A.back() == N)
			result = max<int>(1, A.size() - 1);
        return result;
    }
};
