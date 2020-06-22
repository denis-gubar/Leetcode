class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		LO.push(num);
		HI.push(LO.top());
        LO.pop();
		if (LO.size() < HI.size())
		{
			LO.push(HI.top());
			HI.pop();
		}
	}

	double findMedian() {
		if (LO.size() == HI.size())
			return 0.5 * (LO.top() + HI.top());
		if (LO.size() < HI.size())
			return HI.top();
		return LO.top();
	}
	priority_queue<int> LO;
	priority_queue<int, vector<int>, greater<int>> HI;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */