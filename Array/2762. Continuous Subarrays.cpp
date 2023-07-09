class Solution {
public:
	long long continuousSubarrays(vector<int>& nums) {
		long long result = 0;
		int N = nums.size();
		deque<int> QA, QB;
		auto remove = [&nums, &QA, &QB](int pos)
		{
			while (!QA.empty() && QA.front() <= pos)
				QA.pop_front();
			while (!QB.empty() && QB.front() <= pos)
				QB.pop_front();
		};
		auto add = [&nums, &QA, &QB, &remove](int pos)
		{
			while (!QA.empty() && nums[QA.front()] <= nums[pos])
				QA.pop_front();
			while (!QA.empty() && nums[QA.back()] <= nums[pos])
				QA.pop_back();
			QA.push_back(pos);
			while (!QB.empty() && nums[QB.front()] >= nums[pos])
				QB.pop_front();
			while (!QB.empty() && nums[QB.back()] >= nums[pos])
				QB.pop_back();
			QB.push_back(pos);
		};
		int a = 0, b = 0;
		while (b < N)
		{
			add(b);
			while (!QA.empty() && !QB.empty() && nums[QA.front()] - nums[QB.front()] > 2)
				remove(a), ++a;	
			result += b - a + 1;
			++b;
		}
		return result;
	}
};

