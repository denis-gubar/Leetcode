class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int N = s.size();
		vector<bool> result(N + 1);
		result[0] = true;
		sort(wordDict.begin(), wordDict.end());
		for(int i = 0; i < N; ++i)
			if (result[i])
			{
				auto first_char = s[i];
				auto it = lower_bound(wordDict.begin(), wordDict.end(), s.substr(i, 1));
				while (it != wordDict.end() && (*it)[0] == first_char)
				{
					auto word_size = it->size();
					if (i + word_size <= N &&
						equal(s.begin() + i, s.begin() + i + word_size,
							(*it).begin(), (*it).end()))
					{
						result[i + word_size] = true;
					}
					++it;
				}
			}
		return result[N];
	}
};