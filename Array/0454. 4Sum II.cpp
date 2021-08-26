class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int result = 0;
		unordered_map<int, int> M;
		for (int a : A)
			for (int b : B)
				++M[a + b];
		for (int c : C)
			for (int d : D)
				if (auto it = M.find(-c - d); it != M.end())
					result += it->second;
		return result;
	}
};