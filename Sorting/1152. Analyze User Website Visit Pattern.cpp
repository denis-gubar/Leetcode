class Solution {
public:
	vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
		vector<string> result;
		int N = username.size();
		set<string> visited;
		map<vector<string>, int> results;
		for(int i = 0; i < N; ++i)
			if (visited.insert(username[i]).second)
			{
				vector<pair<int, string>> seq;
				for(int j = 0; j < N; ++j)
					if (username[j] == username[i])
						seq.push_back({ timestamp[j], website[j] });
				sort(seq.begin(), seq.end());
                int const K = seq.size();                
				if (K >= 3)
				{
                    set<vector<string>> X;
                    for(int a = 0; a < K - 2; ++a)
                        for(int b = a + 1; b < K - 1; ++b)
                            for(int c = b + 1; c < K; ++c)
					            X.insert({seq[a].second, seq[b].second, seq[c].second});
                    for(vector<string> const& V : X)
                        ++results[V];
				}
			}
		int best = 0;
		for(auto const& r: results)
        {
			if (r.second > best || r.second == best && r.first < result)
			{
				best = r.second;
				result = r.first;
			}
        }
		return result;
	}
};