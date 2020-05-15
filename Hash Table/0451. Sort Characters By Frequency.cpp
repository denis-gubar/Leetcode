class Solution {
public:
	string frequencySort(string s) {
		string result;
		unordered_map<char, int> M;
		for (char c : s)
			++M[c];
		vector<pair<int, char>> A;
		for (auto m : M)
			A.push_back({ -m.second, m.first });
		sort(A.begin(), A.end());
		for (auto a : A)
            for(int k = 0; k < -a.first; ++k)
			    result += a.second;
		return result;
	}
};