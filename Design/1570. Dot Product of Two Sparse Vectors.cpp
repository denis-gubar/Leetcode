class SparseVector {
public:

	SparseVector(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i])
				data.push_back({ i, nums[i] });
	}

	// Return the dotProduct of two sparse vectors
	int dotProduct(SparseVector& vec) {
		int result = 0;
		int a = 0, b = 0;
		while (a < data.size() && b < vec.data.size())
		{
			if (data[a].first == vec.data[b].first)
            {
				result += data[a].second * vec.data[b].second;
                ++a, ++b;
            }
			else if (data[a].first < vec.data[b].first)
				++a;
			else
				++b;
		}
		return result;
	}
	vector<pair<int, int>> data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);