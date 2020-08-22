class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>	result;
		deque<int> Q;
		auto remove = [&nums, &Q](int pos)
		{
			while (!Q.empty() && Q.front() <= pos)
				Q.pop_front();
		};
		auto add = [&nums, &Q, &remove, k](int pos)
		{
            while (!Q.empty() && nums[Q.front()] <= nums[pos])
                Q.pop_front();
            while (!Q.empty() && nums[Q.back()] <= nums[pos])
                Q.pop_back();
			Q.push_back(pos);
		};
		for (int i = 0; i < k; ++i)
			add(i);
		result.push_back(nums[Q.front()]);
		for (int i = k; i < nums.size(); ++i)
		{            
			remove(i - k);
			add(i);
			result.push_back(nums[Q.front()]);
		}
		return result;
	}
};