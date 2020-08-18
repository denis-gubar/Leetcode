class Solution {
public:
	int maxDistance(vector<int>& position, int m) {
		int a = 0, b = 1'000'000'001;
		sort(position.begin(), position.end());
		auto calc = [&position, m](int A)
		{
			int x = position[0];
			int count = 1;
			for (int i = 1; i < position.size(); ++i)
				if (position[i] - x >= A)
					++count, x = position[i];
			return count >= m;
		};
		while (a + 1 < b)
		{
			int mid = (a + b) / 2;
			if (calc(mid))
				a = mid;
			else
				b = mid;
		}
		return a;
	}
};