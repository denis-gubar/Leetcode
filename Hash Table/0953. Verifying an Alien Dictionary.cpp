class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		vector<vector<int>> A;
		for (const string& word : words)
		{
			A.push_back({});
			for (int c : word)
				A.back().push_back(order.find(c));
		}
		return is_sorted(A.begin(), A.end());
	}
};