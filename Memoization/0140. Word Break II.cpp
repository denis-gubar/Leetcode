class Solution {
public:
	void calc(string const& s, vector<unordered_set<int>> const& F, string& t, int pos, vector<string>& result)
	{
		if (pos == 0)
		{
			result.push_back({});
            reverse_copy(t.begin(), t.end(), back_inserter(result.back()));
			return;
		}
		for (int next_pos : F[pos])
		{
			auto prev_t_size = t.size();
            if (!t.empty())
                t += ' ';
			reverse_copy(s.begin() + next_pos, s.begin() + pos, back_inserter(t));
			calc(s, F, t, next_pos, result);
			t.erase(t.begin() + prev_t_size, t.end());
		}
	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> result;
		int N = s.size();
		vector<unordered_set<int>> F(N + 1);
		sort(wordDict.begin(), wordDict.end());
		for (int i = 0; i < N; ++i)
			if (!i || !F[i].empty())
			{
				auto first_letter = s[i];
				auto it = lower_bound(wordDict.begin(), wordDict.end(), s.substr(i, 1));
				while (it != wordDict.end() && (*it)[0] == first_letter)
				{
					if (i + (*it).size() <= s.size() &&
						equal(s.begin() + i, s.begin() + i + (*it).size(),
							(*it).begin(), (*it).end()))
					{
						F[i + (*it).size()].insert(i);
					}
					++it;
				}
			}
		string t;
		t.reserve(2 * N + 1);
		calc(s, F, t, N, result);
		return result;
	}
};