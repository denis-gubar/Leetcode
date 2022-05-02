class Solution {
public:
	double minmaxGasDist(vector<int>& stations, int k) {
		double a = 0, b = stations.back() - stations[0];
		sort(stations.begin(), stations.end());
		vector<int> D;
		adjacent_difference(stations.begin(), stations.end(), back_inserter(D));
		sort(D.begin() + 1, D.end());
		int N = D.size();
		auto check = [&D, k, N](double m)
		{
			int pos = N - 1;
			int K = k;
			while (K >= 0 && pos > 0 && D[pos] > m)
			{
				K -= static_cast<int>(D[pos] / m);
				--pos;
			}
			return K >= 0;
		};
		for (int z = 0; b - a > 1e-9 && z < 100; ++z)
		{
			double m = (a + b) / 2;
			if (check(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};