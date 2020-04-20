class Solution {
public:
	int findMinFibonacciNumbers(int k) {
		int result = 0;
		vector<int> F{ 0, 1, 1 };
		while (F.back() < 1'000'000'000)
			F.push_back(F[F.size() - 2] + F[F.size() - 1]);
		while (k)
		{
			++result;
			auto it = lower_bound(F.begin(), F.end(), k + 1);
			--it;
			k -= *it;
		}
		return result;
	}
};