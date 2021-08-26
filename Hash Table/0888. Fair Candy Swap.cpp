class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int a = accumulate(A.begin(), A.end(), 0);
		int b = accumulate(B.begin(), B.end(), 0);
		int s = (a + b) / 2;
		set<int> S;
		for (int x : A)
			S.insert(x);
		for (int y : B)
		{
			int x = s - (b - y);
			if (S.find(x) != S.end())
				return { x, y };
		}
		return {};
	}
};
