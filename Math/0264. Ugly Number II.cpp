class Solution {
public:
	int nthUglyNumber(int n) {
		double maxUglyNumber = 2.13e9;
		double lMax = log(maxUglyNumber);
		double l2 = log(2.0);
		double l3 = log(3.0);
		double l5 = log(5.0);
		vector<double> S;
		for (int p2 = 0, p2e = lMax / l2; p2 <= p2e; ++p2)
			for (int p3 = 0, p3e = (lMax - p2 * l2) / l3; p3 <= p3e; ++p3)
				for (int p5 = 0, p5e = (lMax - p2 * l2 - p3 * l3) / l5; p5 <= p5e; ++p5)
					S.push_back( p2 * l2 + p3 * l3 + p5 * l5);
        sort(S.begin(), S.end());
		int result = exp(S[n - 1]) + 0.5;
		return result;
	}
};
