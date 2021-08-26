class NumArray {
public:
	NumArray(vector<int>& nums) : data{ 0 } {
		partial_sum(nums.begin(), nums.end(), back_inserter(data));
	}

	int sumRange(int i, int j) {
		return data[j + 1] - data[i];
	}
	vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */