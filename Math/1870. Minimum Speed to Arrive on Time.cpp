class Solution {
public:
	int minSpeedOnTime(vector<int>& dist, double hour) {
		int N = dist.size();
		if (hour < N - 1.0 + 1e-6)
			return -1;
		int a = 0, b = *max_element(dist.begin(), dist.end()) * 100;
		auto calc = [&dist, hour](double velocity)
		{
			double x = 0;
			for (double d : dist)
			{
				if (x - floor(x) > 1e-9)
					x = floor(x) + 1.0;
				x += d / velocity;
			}            
			return x - 1e-9 < hour;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};