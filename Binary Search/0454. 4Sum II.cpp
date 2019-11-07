class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int result = 0;
		int N = A.size();
		map<int, int> AB, CD;
		for (int a : A)
			for (int b : B)
				++AB[a + b];
		for (int c : C)
			for (int d : D)
				++CD[-c - d];
		for (auto ab : AB)
		{
			auto it = CD.find(ab.first);
			if (it != end(CD))
				result += it->second * ab.second;
		}
		return result;
	}
};