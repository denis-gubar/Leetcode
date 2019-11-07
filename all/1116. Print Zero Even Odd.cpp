class ZeroEvenOdd {
private:
	int n;
	mutex m;
	condition_variable cv;
	int state;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		state = 0;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
        while(state < n * 2 - 1)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() {return state % 2 == 0; });
            printNumber(0);
            ++state;
            cv.notify_all();
        }
	}

	void even(function<void(int)> printNumber) {
        while(state < n * 2 - 2)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() {return state % 4 == 3; });
            printNumber(state / 2 + 1);
            ++state;
            cv.notify_all();
        }
	}

	void odd(function<void(int)> printNumber) {
        while(state < n * 2)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() {return state % 4 == 1; });
            printNumber(state / 2 + 1);
            ++state;
            cv.notify_all();
        }
	}
};