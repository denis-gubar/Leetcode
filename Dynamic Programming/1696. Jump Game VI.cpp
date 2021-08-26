class Solution {
public:
	int maxResult(vector<int>& nums, int k) {
		int N = nums.size();
		vector<int> F(N, -1'000'000'000);
		F[0] = nums[0];
		deque<int> Q;
		auto remove = [&F, &Q](int pos)
		{
			while (!Q.empty() && Q.front() <= pos)
				Q.pop_front();
		};
		auto add = [&F, &Q, k](int pos)
		{
			while (!Q.empty() && F[Q.front()] <= F[pos])
				Q.pop_front();
			while (!Q.empty() && F[Q.back()] <= F[pos])
				Q.pop_back();
			Q.push_back(pos);
		};
		add(0);
		for (int i = 1; i < N; ++i)
		{
			if (i + 1 >= k)
				remove(i - k - 1);
			F[i] = nums[i] + F[Q.front()];
			add(i);
		}
		return F[N - 1];
	}
};