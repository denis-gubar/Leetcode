class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> result;
		int N = nums.size();
		nums.push_back(1);
		sort(nums.begin(), nums.end());
		vector<int> F(N + 1), P(N + 1);
		F[0] = 1;
		for (int prev = 0; prev < N; ++prev)
            for (int next = prev + 1; next <= N; ++next)
                if (F[next] <= F[prev] && nums[next] % nums[prev] == 0)
                {
                    F[next] = F[prev] + 1;
                    P[next] = prev;
                }
		int pos = max_element(F.begin(), F.end()) - F.begin();
		while (pos)
		{
			result.push_back(nums[pos]);
			pos = P[pos];
		}
		return result;
	}
};