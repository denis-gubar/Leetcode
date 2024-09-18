class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size): sum(0.0), size(size) {
	}

	double next(int val) {
		data.push_back(val);
		sum += val;
		if (data.size() > size)
			sum -= data.front(), data.pop_front();
		return sum / data.size();
	}
	deque<int> data;
	double sum;
	size_t size;
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */