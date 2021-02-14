class Solution {
public:
	int countPairs(vector<int>& deliciousness) {
		int const MOD = 1'000'000'007;
		long long result = 0;
		unordered_map<long long, long long> M;
		for (int d : deliciousness)
			++M[d];
		vector<int> A{ 1 };
		for (int i = 1; i <= 25; ++i)
			A.push_back(A.back() << 1);
		for (auto it = M.begin(); it != M.end(); ++it)
			for (auto z = lower_bound(A.begin(), A.end(), it->first); z != A.end(); ++z)
			{
				int x = *z - it->first;
                if (x < it->first)
                    continue;
                if (x == it->first)
                {
                    if (x > 0)
                    {
                        result += 1LL * it->second * (it->second - 1) / 2;
                        result %= MOD;
                    }
                    continue;
                }
				auto it2 = M.find(x);
				if (it2 != M.end())
				{
					result += 1LL * it->second * it2->second;
					result %= MOD;
				}
			}
		return result;
	}
};