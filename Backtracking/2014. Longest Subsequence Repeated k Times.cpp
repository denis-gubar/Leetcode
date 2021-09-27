class Solution {
public:
	bool check(string const& s)
	{
		if (s.empty())
			return true;
        int pos = P[I[s[0]]][0];
        for(int k = 0; k < K; ++k)
        {
            for (int i = 0; i < s.size(); ++i)
                if (k > 0 || k == 0 && i > 0)
                {
                    if (pos == N)
                        return false;
                    pos = next[I[s[i]]][pos];
                }
        }
		return pos < N;
	}
	void calc(string& s)
	{
		if (!check(s))
			return;
		else if (s.size() >= result.size())
			result = s;
		for (int j = 0; j < Z; ++j)
			if (A[alphabet[j]] >= K)
			{
				A[alphabet[j]] -= K;
				s.push_back(alphabet[j]);
				calc(s);
				s.pop_back();
				A[alphabet[j]] += K;
			}
	}
	string longestSubsequenceRepeatedK(string s, int k) {
		x.clear();
		K = k;
		A = vector<int>(256);
		for (char c : s)
			++A[c];
		for (char c : s)
			if (A[c] >= k)
				x += c;
		result.clear();
		alphabet = x;
		sort(alphabet.begin(), alphabet.end());
		alphabet.resize(unique(alphabet.begin(), alphabet.end()) - alphabet.begin());
		Z = alphabet.size();
		N = x.size();
		I = vector<int>(256);
		for (int i = 0; i < Z; ++i)
			I[alphabet[i]] = i;
		P = vector<vector<int>>(Z);
		for (int i = 0; i < N; ++i)
			P[I[x[i]]].push_back(i);
		for (int j = 0; j < Z; ++j)
			P[j].push_back(N);
		next = vector<vector<int>>(Z, vector<int>(N));
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < Z; ++j)
				next[j][i] = *upper_bound(P[j].begin(), P[j].end(), i);
		string t;
		calc(t);
		return result;
	}
	int K;
	int Z;
	int N;
	vector<vector<int>> P;
	vector<int> A;
	vector<int> I;
	string x;
	string alphabet;
	string result;
	vector<vector<int>> next;
};