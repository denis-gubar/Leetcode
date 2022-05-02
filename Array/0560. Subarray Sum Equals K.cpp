class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		int result = 0;
		unordered_map<int, int> M;        
		int sum = 0;
        ++M[sum];
		for (int n : nums)
		{
            sum += n;
			int other = sum - k;
			if (auto it = M.find(other); it != M.end())
				result += it->second;
			++M[sum];
			
		}
		return result;
	}
};