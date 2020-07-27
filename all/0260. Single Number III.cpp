class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_set<int> result;
		if (count(nums.begin(), nums.end(), 0) == 1)
			result.insert(0);
		unsigned int k = 1;
		while (result.size() < 2)
		{
			int count = 0;
			unsigned int current = 0;
			for (unsigned int n : nums)
				if (n & k)
				{
					++count;
					current ^= n;
				}
			if (count % 2)
				result.insert(static_cast<int>(current));
			k <<= 1;
		}
		return vector<int>(result.begin(), result.end());
	}
};