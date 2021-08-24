class Solution {
public:
	vector<int> recoverArray(int n, vector<int> sums) {
		vector<int> result;
		sort(sums.begin(), sums.end());
		unordered_map<int, int> M;
		for (int x : sums)
			++M[x];
		int delta = sums.back() - sums[sums.size() - 2];
		for (int x = -delta; x <= delta; x += 2 * delta)
			if (M.find(x) != M.end())
			{
				unordered_map<int, int> F = M;
				vector<int> newSums;
				bool isOk = true;
				if (x == 0)
				{
					for (int i = 0; i < (1 << n); ++i)
						if (F[sums[i]] > 0)
						{
							if (F[sums[i]] > 1)
								F[sums[i]] -= 2;
							else
							{
								isOk = false;
								break;
							}
						}
					if (isOk)
					{
						F = M;
						for (int i = 0; i < (1 << n); ++i)
							if (F[sums[i]] > 0)
							{
								F[sums[i]] -= 2;
								newSums.push_back(sums[i]);
							}
					}
				}
				else if (x > 0)
				{
					for (int i = 0; i < (1 << n); ++i)
						if (F[sums[i]] > 0)
						{
							if (F[sums[i] + x] > 0)
								--F[sums[i]], --F[sums[i] + x];
							else
							{
								isOk = false;
								break;
							}
						}
					if (isOk)
					{
						F = M;
						for (int i = 0; i < (1 << n); ++i)
							if (F[sums[i]] > 0)
							{
								--F[sums[i]], --F[sums[i] + x];
								newSums.push_back(sums[i]);
							}
					}
				}
				else
				{
					for (int i = (1 << n) - 1; i >= 0; --i)
						if (F[sums[i]] > 0)
						{
							if (F[sums[i] + x] > 0)
								--F[sums[i]], --F[sums[i] + x];
							else
							{
								isOk = false;
								break;
							}
						}
					if (isOk)
					{
						F = M;
						for (int i = (1 << n) - 1; i >= 0; --i)
							if (F[sums[i]] > 0)
							{
								--F[sums[i]], --F[sums[i] + x];
								newSums.push_back(sums[i]);
							}
					}
				}
				if (isOk)
				{
					if (n > 1)
                    {
						result = recoverArray(n - 1, newSums);
	    				if (result.empty())
    						continue;
                    }
					result.push_back(x);
					break;
				}
			}
		return result;
	}
};