class Solution {
public:
	template<typename T> static T gcd(T a, T b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	bool hasGroupsSizeX(vector<int>& deck) {
		map<int, int> M;
		for (int d : deck)
			++M[d];
		int k = M.begin()->second;
		for (auto& m : M)
			k = gcd(k, m.second);
		return k > 1;
	}
};
