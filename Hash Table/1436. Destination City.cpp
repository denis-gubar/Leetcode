class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		map<string, int> M0, M1;
		for (vector<string> const& path : paths)
			++M0[path[0]], ++M1[path[1]];
		for (auto m : M1)
			if (m.second == 1 && M0.find(m.first) == M0.end())
				return m.first;
		return {};
	}
};