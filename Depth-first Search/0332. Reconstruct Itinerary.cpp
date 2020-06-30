class Solution {
public:
	void calc(string const& from, unordered_map<string, vector<string>>& M, vector<string>& result)
	{
		while(!M[from].empty())
		{
			string to = move(M[from].back());
			M[from].pop_back();
			calc(to, M, result);
		}
		result.push_back(from);
	}
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> result;
		unordered_map<string, vector<string>> M;
		for (vector<string> const& ticket : tickets)
			M[ticket[0]].push_back(ticket[1]);
		for (auto& m : M)
			sort(m.second.begin(), m.second.end(), greater<string>());
		calc("JFK", M, result);
		reverse(result.begin(), result.end());
		return result;
	}
};