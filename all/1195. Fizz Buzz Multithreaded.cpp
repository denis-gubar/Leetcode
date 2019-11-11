class FizzBuzz {
private:
	int n;
	int current;
	mutex m;
	condition_variable cv;
public:
	FizzBuzz(int n) {
		this->n = n;
		current = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (current <= n)
		{
			unique_lock<mutex> lock(m);
			cv.wait(lock, [this]() {return current % 5 != 0 && current % 3 == 0 || current > n; });
			if (current <= n)
				printFizz();
			++current;
			cv.notify_all();
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (current <= n)
		{
			unique_lock<mutex> lock(m);
			cv.wait(lock, [this]() {return current % 3 != 0 && current % 5 == 0 || current > n; });
			if (current <= n)
				printBuzz();
			++current;
			cv.notify_all();
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (current <= n)
		{
			unique_lock<mutex> lock(m);
			cv.wait(lock, [this]() {return current % 15 == 0 || current > n; });
			if (current <= n)
				printFizzBuzz();
			++current;
			cv.notify_all();
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (current <= n)
		{
			unique_lock<mutex> lock(m);
			cv.wait(lock, [this]() {return current % 3 != 0 && current % 5 != 0 || current > n; });
			if (current <= n)
				printNumber(current);
			++current;
			cv.notify_all();
		}
	}
};