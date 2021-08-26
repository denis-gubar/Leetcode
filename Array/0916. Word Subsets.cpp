class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> result;
		map<int, int> M;
		for (const string& b : B)
		{
			map<int, int> current;
			for (int c : b)
				++current[c];
			for (auto& p : current)
				M[p.first] = max(M[p.first], p.second);
		}
		for (const string& a : A)
		{
			map<int, int> current;
			for (int c : a)
				++current[c];
			bool isSubset = true;
			for (auto& p : M)
				if (p.second > current[p.first])
				{
					isSubset = false;
					break;
				}
			if (isSubset)
				result.push_back(a);
		}
		return result;
	}
};