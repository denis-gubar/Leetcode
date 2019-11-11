class BoundedBlockingQueue {
	mutex m;
	condition_variable cv;
	queue<int> Q;
	int capacity;
public:
	BoundedBlockingQueue(int capacity): capacity(capacity) {

	}

	void enqueue(int element) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [this]() {return Q.size() < capacity; });
		Q.push(element);
		cv.notify_all();
	}

	int dequeue() {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [this]() {return !Q.empty(); });
		int result = Q.front(); Q.pop();
		cv.notify_all();
		return result;
	}

	int size() {
		unique_lock<mutex> lock(m);
		int result = Q.size();
		return result;
	}
};