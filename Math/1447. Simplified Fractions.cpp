class Solution {
public:
	static int gcd(int a, int b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	vector<string> simplifiedFractions(int n) {
		set<string> S;
		for (int k = 1; k < n; ++k)
            for(int k2 = k + 1; k2 <= n; ++k2)
            {
                int a = gcd(k, k2);
                S.insert(to_string(k / a) + "/" + to_string(k2 / a));
            }
		return vector<string>(S.begin(), S.end());
	}
};