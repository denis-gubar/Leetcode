class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		set<pair<int, int>> S;
		for (int x : nums)
		{
			int n = x;
			while ((n & 1) == 0)
				n >>= 1;
			if (n == x)
				x *= 2;
			S.insert({ n, x });
		}
		auto [a, amax] = *S.begin();
		auto [b, bmax] = *S.rbegin();
		int result = b - a;
		while (true)
		{
			auto [a, amax] = *S.begin();
			if (a < amax)
			{
				S.erase(S.begin());
				S.insert({ a * 2, amax });
				if (a * 2 > b)
					b = a * 2;
                auto [na, namax] = *S.begin();
                a = na;
                if (result > b - a)
                    result = b - a;
			}
			else
				return result;
		}
	}
};