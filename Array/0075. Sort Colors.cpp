class Solution {
public:
	void sortColors( vector<int>& nums ) {
		int r = count( nums.begin(), nums.end(), 0 );
		int w = count( nums.begin(), nums.end(), 1 );
		int b = count( nums.begin(), nums.end(), 2 );
		int i = 0;
		for (int k = 0; k < r; ++i, ++k)
			nums[i] = 0;
		for (int k = 0; k < w; ++i, ++k)
			nums[i] = 1;
		for (int k = 0; k < b; ++i, ++k)
			nums[i] = 2;
	}
};