class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int N = nums.size();
        if (!N)
            return false;
		multiset<int> S;
		auto check = [&S, t](int x)
		{
			auto it = S.insert(x);
			if (it != S.begin() && static_cast<long long>(*it) - *prev(it) <= t)
				return true;
			auto prevIt = it;
			++it;
			return it != S.end() && static_cast<long long>(*it) - *prevIt <= t;
		};
		for (int i = 0; i <= k && i < N; ++i)
			if (check(nums[i]))
				return true;
		for (int i = k + 1; i < N; ++i)
		{
			S.erase(S.find(nums[i - k - 1]));
			if (check(nums[i]))
				return true;
		}
		return false;
	}
};