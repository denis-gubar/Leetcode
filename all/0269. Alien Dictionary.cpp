class Solution {
public:
	string alienOrder(vector<string>& words) {
		string result;
		unordered_set<char> S;
		for (string const& w : words)
			for (char c : w)
				S.insert(c);
		int N = words.size();
		unordered_map<char, unordered_set<char>> connectivity;
		for (int i = 1; i < N; ++i)
        {
			for (int j = 0; j < words[i - 1].size() && j < words[i].size(); ++j)
				if (words[i][j] != words[i - 1][j])
				{
					connectivity[words[i][j]].insert(words[i - 1][j]);
					break;
				}
            if (words[i].size() < words[i - 1].size() && words[i - 1].substr(0, words[i].size()) == words[i])
                    return {};
        }
		bool changed = true;
		while (changed)
		{
			changed = false;
			unordered_set<char> visited(S);
			for (char V : S)
				for (char U : connectivity[V])
				{
					auto it = visited.find(U);
					if (it != visited.end())
						visited.erase(it);
				}
			changed = !visited.empty();
			result += string(visited.begin(), visited.end());
			for (char V : visited)
				S.erase(V);
		}
		if (!S.empty())
			return {};
		reverse(result.begin(), result.end());
		return result;
	}
};