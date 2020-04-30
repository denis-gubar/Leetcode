class Solution {
public:
	void updateQueue(deque<int>& Q, vector<int> const& A, int i, int k)
	{
		if (!Q.empty() && Q.front() == i - k)
			Q.pop_front();
		while (!Q.empty() && A[i] > A[Q.back()])
			Q.pop_back();
        Q.push_back(i);
	}
	int constrainedSubsetSum(vector<int>& nums, int k) {
		int minResult = *max_element(nums.begin(), nums.end());
		int N = nums.size();
		int current = 0;
		vector<int> A{ 0 };
		deque<int> Q;
		for (int i = 0; i < N; ++i)
		{
			updateQueue(Q, A, i, k);
			int current = 0;
			if (!Q.empty())
				current = max(current, A[Q.front()]);
			A.push_back(max(0, current + nums[i]));
		}
		int result = *max_element(A.begin(), A.end());
		if (minResult <= 0)
			result = minResult;
		return result;
	}
};