class H2O {
	mutex m;
	condition_variable cv;
	int H;
	int O;
	int releasedCount;
public:
	H2O() {
		H = O = releasedCount = 0;
	}

	void hydrogen(function<void()> releaseHydrogen) {
		unique_lock<mutex> lock(m);
		++H;
		int block = (H + 1) / 2;
		cv.notify_all();
		cv.wait(lock, [this, block]() { return block <= 2 * H && block <= O && releasedCount / 3 == block - 1; });
		++releasedCount;
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		cv.notify_all();
	}

	void oxygen(function<void()> releaseOxygen) {
		unique_lock<mutex> lock(m);
		int block = ++O;
		cv.notify_all();
		cv.wait(lock, [this, block]() { return H >= 2 * block && releasedCount / 3 == block - 1; });
		++releasedCount;
		// releaseOxygen() outputs "O". Do not change or remove this line.        
		releaseOxygen();
		cv.notify_all();
	}
};