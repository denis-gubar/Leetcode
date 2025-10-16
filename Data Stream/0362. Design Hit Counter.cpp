class HitCounter {
public:
	/** Initialize your data structure here. */
	HitCounter() {

	}

	/** Record a hit.
		@param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		data.push(timestamp);
	}

	/** Return the number of hits in the past 5 minutes.
		@param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		while (!data.empty() && data.front() + 300 <= timestamp)
			data.pop();
		return data.size();
	}
	queue<int> data;
};
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */