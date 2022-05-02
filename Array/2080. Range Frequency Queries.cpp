class RangeFreqQuery {
public:
	RangeFreqQuery(vector<int>& arr) {		
		int N = arr.size();
		A = vector<vector<int>>(10'001);
		for (int i = 0; i < N; ++i)
			A[arr[i]].push_back(i);		
	}

	int query(int left, int right, int value) {
		auto L = lower_bound(A[value].begin(), A[value].end(), left);
		auto R = upper_bound(A[value].begin(), A[value].end(), right);
		return R - L;
	}
	vector<vector<int>> A;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */