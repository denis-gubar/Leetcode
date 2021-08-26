class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> result;
		map<int, int> M;
		set<pair<int, int>> S;
		for (int b : barcodes)
			++M[b];
		for (auto m : M)
			S.insert({ -m.second, m.first });
		while (!S.empty())
		{
			auto it = S.begin();
			if (!result.empty() && S.begin()->second == result.back())
				++it;
			auto p = *it;
			++p.first;
			result.push_back(p.second);
			S.erase(it);
			if (p.first)
				S.insert({ p.first, p.second });
		}
		return result;
	}
};