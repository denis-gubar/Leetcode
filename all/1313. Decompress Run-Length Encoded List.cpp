class Solution {
public:
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i += 2)
		{
			int a = nums[i], b = nums[i + 1];
			for(int k = 0; k < a; ++k)
				result.push_back(b);
		}
		return result;
	}
};