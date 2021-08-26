class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int N = s.size();
		vector<bool> F(N);
		F[0] = true;
		set<int> S;
		for (int i = 0; i < N; ++i)
			if (s[i] == '0')
				S.insert(i);
		for (int pos = 0; pos < N; ++pos)
		{
			while (!S.empty() && *S.begin() <= pos)
				S.erase(S.begin());
			if (F[pos])
			{
				for (auto it = S.lower_bound(pos + minJump); it != S.end() && *it <= pos + maxJump;)
				{
					F[*it] = true;
					it = S.erase(it);
				}					
			}
		}
		return F[N - 1];
	}
};