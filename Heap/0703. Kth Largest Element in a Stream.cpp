class KthLargest {
public:
	KthLargest(int k, vector<int> nums) : k(k) {
		if (k - 1 == nums.size())
			nums.push_back(numeric_limits<int>::lowest());
		sort(nums.begin(), nums.end(), comparator);
		heap = vector<int>{ nums.begin(), nums.begin() + k };
		make_heap(heap.begin(), heap.end(), comparator);
	}

	int add(int val) {
		if (heap[0] <= val)
		{
			pop_heap(heap.begin(), heap.end(), comparator);
			heap.back() = val;
			push_heap(heap.begin(), heap.end(), comparator);
		}
		return heap[0];
	}
	greater<int> comparator;
	vector<int> heap;
	int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */