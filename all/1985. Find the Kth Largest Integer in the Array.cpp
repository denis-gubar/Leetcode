class Solution {
public:
	string kthLargestNumber(vector<string>& nums, int k) {
		auto comp = [](string const& a, string const& b)
		{
			if (a.size() != b.size())
				return a.size() < b.size();
			return a < b;
		};
        int N = nums.size();
		nth_element(nums.begin(), nums.begin() + (N - k), nums.end(), comp);
		return nums[N - k];
	}
};