class Solution{
public:
	int removeElement( vector<int>& nums, int val ) {
		nums.erase(nums.begin(), partition( nums.begin(), nums.end(), bind1st( equal_to<int>(), val )));
		return nums.size();
	}
};