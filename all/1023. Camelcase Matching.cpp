class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> result;
		for (string const& query : queries)
		{
			bool current = true;
			int a = 0, b = 0;
			while (a < query.size() || b < pattern.size())
			{
				if (b < pattern.size())
				{
					if (a == query.size())
					{
						current = false;
						break;
					}
					if (query[a] == pattern[b])
						++a, ++b;
					else if (isupper(query[a]))
					{
						current = false;
						break;
					}
					else
					{
						++a;
					}
				}
				else
				{
					if (isupper(query[a]))
					{
						current = false;
						break;
					}
					++a;
				}
			}
			result.push_back(current);
		}
		return result;
	}
};