class NumArray {
public:
	NumArray(vector<int>& nums) {
		sums.reserve(16);
		sums.push_back(nums);
		while (sums.back().size() > 1)
		{
			vector<int>& last = sums.back();			
			vector<int> current;
			for (int i = 0; i < last.size(); ++i)
			{
				if (i % 2 == 0)
					current.push_back(last[i]);
				else
					current.back() += last[i];
			}
			sums.push_back(current);
		}
        for(int level = 0; level < sums.size(); ++level)
            sums[level].push_back(0);
	}

	void update(int index, int val) {
		int delta = val - sums[0][index];
		for (int level = 0; level < sums.size(); ++level)
			sums[level][index >> level] += delta;
	}

	int sumRange(int left, int right) {
		int result = 0;
		int level = 0;
		while (left < right)
		{
			if (left % 2 == 1)
				result -= sums[level][left - 1];
			if (right % 2 == 0)
				result -= sums[level][right + 1];
			++level;
			left >>= 1;
			right >>= 1;
		}
		result += sums[level][left];
		return result;
	}
	vector<vector<int>> sums;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */