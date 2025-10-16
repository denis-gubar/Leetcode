class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		sort(target.begin(), target.end());
		vector<string> S;
		for (int i = 0; i < stickers.size(); ++i)
		{
			string s;
			for (int j = 0; j < stickers[i].size(); ++j)
				if (target.find(stickers[i][j]) != string::npos)
					s += stickers[i][j];
			sort(s.begin(), s.end());
			if (!s.empty() && find(S.begin(), S.end(), s) == S.end())
			{
				S.push_back(s);
			}				
		}
		string total(accumulate(S.begin(), S.end(), string()));
		sort(total.begin(), total.end());
		total.erase(unique(total.begin(), total.end()), total.end());
		string t(target);
		t.erase(unique(t.begin(), t.end()), t.end());
		if (total != t)
			return -1;
		queue<string> Q; queue<int> A;
		Q.push(target); A.push(0);
		set<string> F;
		while (!Q.empty())
		{
			t = Q.front(); Q.pop();
			int step = A.front(); A.pop();
			for (int i = 0; i < S.size(); ++i)
				if (find(S[i].begin(), S[i].end(), t[0]) != S[i].end() )
				{
					int x = 0, y = 0;
					string new_target;
					while (x < t.size() && y < S[i].size())
					{
						if (t[x] == S[i][y])
						{
							++x; ++y;
						}
						else if (t[x] < S[i][y])
						{
							new_target += t[x];
							++x;
						}
						else
						{
							++y;
						}

					}
					while (x < t.size())
					{
						new_target += t[x];
						++x;
					}
					if (new_target.empty())
						return step + 1;
					if (F.find(new_target) == F.end())
					{
						F.insert(new_target);
						Q.push(new_target); A.push(step + 1);
					}
				}

		}
		return -1;
	}
};