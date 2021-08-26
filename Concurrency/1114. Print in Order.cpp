class Foo {
	enum struct State
	{
		beforeFirst, beforeSecond, beforeThird
	} state;
	mutex m;
	condition_variable cv;
public:
	Foo() {
		state = State::beforeFirst;
	}

	void first(function<void()> printFirst) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [this] {return state == State::beforeFirst; });
		printFirst();
		state = State::beforeSecond;
		cv.notify_all();
	}

	void second(function<void()> printSecond) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [this] {return state == State::beforeSecond; });
		printSecond();
		state = State::beforeThird;
		cv.notify_all();
	}

	void third(function<void()> printThird) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [this] {return state == State::beforeThird; });
		printThird();
		state = State::beforeFirst;
		cv.notify_all();
	}
};