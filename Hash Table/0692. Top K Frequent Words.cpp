class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> result;
		unordered_map<string, int> M;
		for (string const& word : words)
			++M[word];
		vector<pair<int, string>> A;
		for (auto const& m : M)
			A.push_back({ -m.second, m.first });
		sort(A.begin(), A.end());
		for (auto const& a : A)
			result.push_back(a.second);
        result.resize(k);
		return result;
	}
};