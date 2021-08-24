class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, long long target) {
		vector<vector<int>> result;
		int N = nums.size();
		map<int, int> M;
		for (int i = 0; i < N; ++i)
			++M[nums[i]];
		map<int, vector<pair<int, int>>> P;
		for (auto it = M.begin(); it != M.end(); ++it)
        {
            auto const& a = *it;
			for (auto it2 = it; it2 != M.end(); ++it2)
            {
                auto const& b = *it2;
				P[a.first + b.first].emplace_back(min(a.first, b.first), max(a.first, b.first));
            }
        }
		for (auto const& [sum, p] : P)
		{
			long long total = target - sum;
            if (total < sum)
                break;
			if (total < numeric_limits<int>::max())
				if (auto it = P.find(total); it != P.end())
				{
					for (auto a : p)
						for (auto b : it->second)
						{
							if (a.second > b.first)
								continue;
							unordered_map<int, int> count;
							++count[a.first]; ++count[a.second];
							++count[b.first]; ++count[b.second];
							if (count[a.first] <= M[a.first] && count[a.second] <= M[a.second] &&
								count[b.first] <= M[b.first] && count[b.second] <= M[b.second])
								result.push_back({ a.first, a.second, b.first, b.second });
						}
				}
		}
		return result;
	}
};