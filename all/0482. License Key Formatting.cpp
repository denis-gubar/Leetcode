class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;
		vector<string> groups;
		for (int i = S.size() - 1; i >= 0; --i)
			if (S[i] != '-')
			{
				if (groups.empty() || groups.back().size() == K)
					groups.push_back(""s);
				groups.back() += ::toupper(S[i]);
			}
		reverse(groups.begin(), groups.end());
		for (int i = 0; i < groups.size(); ++i)
		{
			if (i) result += '-';
			reverse_copy(groups[i].begin(), groups[i].end(), back_inserter(result));
		}
		return result;
	}
};